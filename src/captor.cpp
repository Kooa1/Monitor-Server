//
// Created by 66 on 2025/12/18.
//

#include "../include/captor.h"

Captor::Captor() {
    av_log_set_level(AV_LOG_ERROR);
}

void Captor::init_context() {
    av_format_context.reset(avformat_alloc_context(), AVFormatContextDeleter());
    av_codec_context.reset(avcodec_alloc_context3(nullptr));
    av_input_format = av_find_input_format("dshow");

    if (!av_format_context || !av_codec_context || !av_input_format) {
        av_log(av_format_context.get(), AV_LOG_ERROR, "check context init");
        av_log(av_codec_context.get(), AV_LOG_ERROR, "alloc context3 failed");
        av_log(&av_input_format, AV_LOG_ERROR, "find input failed");
        return;
    }

    av_format_context->probesize = 100000000;
    av_format_context->max_analyze_duration = 5 * AV_TIME_BASE;

    AVDictionary *option = nullptr;
    av_dict_set(&option, "framerate", "30", 0);
    av_dict_set(&option, "video_size", "1920x1080", 0);

    int ret = avformat_open_input(&av_format_context.get(), ":0.0", av_input_format, &option);
}
