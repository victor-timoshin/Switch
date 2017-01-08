#include <setjmp.h>

extern "C" {
#include <jpeglib.h>
}

#include <Pcf/System/Object.h>
#include <Pcf/UniquePointer.h>
#include <Pcf/System/IO//BinaryReader.h>

#include "../../../../Includes/Pcf/System/Drawing/Image.h"
#include "../../../../Includes/Pcf/System/Drawing/Imaging/FrameDimension.h"

struct JpegErrorMgr {
  jpeg_error_mgr	pub_;
  jmp_buf		errhand_;
};

extern "C" {
  static void
  JpegErrorHandler(j_common_ptr dinfo) {
    longjmp(((JpegErrorMgr *)(dinfo->err))->errhand_, 1);
  }

  static void
  JpegOutputHandler(j_common_ptr) {
  }
}

namespace Pcf {
  namespace System {
    namespace Drawing {
      class Jpg : public object {
      public:
        Jpg(System::IO::Stream& stream) : reader(stream) {}

        void Read(Image& image) {
          Array<byte> streamData((int32)reader.BaseStream().Length());
          UniquePointer<byte[]> rawData;
          jpeg_decompress_struct dinfo;
          JpegErrorMgr jerr;
          JSAMPROW row;

          char* max_finish_decompress_err;
          char* max_destroy_decompress_err;

          dinfo.err = jpeg_std_error((jpeg_error_mgr *)&jerr);
          jerr.pub_.error_exit = JpegErrorHandler;
          jerr.pub_.output_message = JpegOutputHandler;

          max_finish_decompress_err = (char*)malloc(1);
          max_destroy_decompress_err = (char*)malloc(1);
          *max_finish_decompress_err= 10;
          *max_destroy_decompress_err= 10;

          if (setjmp(jerr.errhand_)) {
            if ( ((*max_finish_decompress_err)-- > 0) && rawData.IsNull())
              jpeg_finish_decompress(&dinfo);
            if ( (*max_destroy_decompress_err)-- > 0)
              jpeg_destroy_decompress(&dinfo);

            free(max_destroy_decompress_err);
            free(max_finish_decompress_err);

            throw OutOfMemoryException(pcf_current_information);
          }

          jpeg_create_decompress(&dinfo);
          reader.Read(streamData, 0, (int32)reader.BaseStream().Length());
          jpeg_mem_src(&dinfo, (byte*)streamData.Data(), (int32)reader.BaseStream().Length());
          jpeg_read_header(&dinfo, 1);

          dinfo.quantize_colors = false;
          dinfo.out_color_space = JCS_RGB;
          dinfo.out_color_components = 3;
          dinfo.output_components = 3;

          jpeg_calc_output_dimensions(&dinfo);

          rawData = new byte[dinfo.output_width * dinfo.output_height * dinfo.output_components];

          jpeg_start_decompress(&dinfo);

          while (dinfo.output_scanline < dinfo.output_height) {
            row = (JSAMPROW)(rawData.ToPointer() + dinfo.output_scanline * dinfo.output_width * dinfo.output_components);
            jpeg_read_scanlines(&dinfo, &row, (JDIMENSION)1);
          }

          ToImage(image, dinfo, rawData);

          jpeg_finish_decompress(&dinfo);
          jpeg_destroy_decompress(&dinfo);

          free(max_destroy_decompress_err);
          free(max_finish_decompress_err);
        }

        void ToImage(Image& image, const jpeg_decompress_struct& dinfo, UniquePointer<byte[]> rawData) {
          image.flags = Imaging::ImageFlags::ReadOnly | Imaging::ImageFlags::HasRealPixelSize | Imaging::ImageFlags::HasRealDpi | Imaging::ImageFlags::ColorSpaceRgb;
          image.frameDimensionList = {Imaging::FrameDimension::Page().Guid};
          //image.horizontalResolution = Convert::ToSingle(dinfo.) / inchesPerMeter;
          image.pixelFormat = Imaging::PixelFormat::Format24bppRgb;
          //image.verticalResolution = Convert::ToSingle(bmpInfo.yPixelsPerMeter) / inchesPerMeter;
          image.size = Size(dinfo.output_width, dinfo.output_height);
          image.rawFormat = Imaging::ImageFormat::Jpeg;
          image.rawData = Array<byte>(rawData.Release(), image.size.Width() * image.size.Height() * (image.PixelFormat() == System::Drawing::Imaging::PixelFormat::Format32bppRgb ? 4 : 3));
        }

      private:
        System::IO::BinaryReader reader;
      };
    }
  }
}
