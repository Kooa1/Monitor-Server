//
// Created by 66 on 2025/12/18.
//

#include "../include/captor.h"

Captor::Captor() {
    av_log_set_level(AV_LOG_INFO);
    // avfoundation_devices_list();
    init_context();
}

void Captor::avfoundation_devices_list() {
    av_input_format = av_find_input_format("dshow");
    if (!av_input_format) {
        av_log(nullptr, AV_LOG_ERROR, "find devices failed\n");
        return;
    }

    av_format_context.reset(avformat_alloc_context(), AVFormatContextDeleter());
    AVDictionary *options = nullptr;
    av_dict_set(&options, "list_devices", "true", 0);

    auto ctx = av_format_context.get();
    if (const int ret = avformat_open_input(&ctx, "0", av_input_format, &options); ret != 0) {
        av_log(nullptr, AV_LOG_ERROR, "open input format failed: %s\n", av_error_cxx(ret).c_str());
        return;
    }
}

void Captor::init_context() {
    AVDictionary *options = nullptr;
    av_dict_set(&options, "framerate", "30", 0);

    auto ctx = av_format_context.get();
    if (const int ret = avformat_open_input(&ctx, "0", av_input_format, &options); ret != 0) {
        av_log(nullptr, AV_LOG_ERROR, "open input format failed: %s\n", av_error_cxx(ret).c_str());
        return;
    }

    if (const int ret = avformat_find_stream_info(av_format_context.get(), nullptr); ret < 0) {
        av_log(nullptr, AV_LOG_ERROR, "found input format failed: %s\n", av_error_cxx(ret).c_str());
        return;
    }

    if (const int ret = av_find_best_stream(av_format_context.get(), AVMEDIA_TYPE_VIDEO, -1, -1, nullptr, 0); ret < 0) {
        av_log(nullptr, AV_LOG_ERROR, "have not best stream: %s\n", av_error_cxx(ret).c_str());
        return;
    } else {
        video_index = ret;
    }

    av_codec_context.reset(avcodec_alloc_context3(nullptr));

    if (const int ret = avcodec_parameters_to_context(av_codec_context.get(),
                                                      av_format_context->streams[video_index]->codecpar); ret < 0) {
        av_log(nullptr, AV_LOG_ERROR, "copy parameters failed: %s\n", av_error_cxx(ret).c_str());
        return;
    }
}
