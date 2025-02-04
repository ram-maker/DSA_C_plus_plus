#include <iostream>
#include <bits/stdc++.h>
#include <memory>
using namespace std;
class AudioCodec{
    public:
    virtual int getFrameSampleSize()=0;

};

class VideoCodec{
    public:
    virtual int getFrameRate()=0;
};

class AAC:public AudioCodec{
    public:
    int getFrameSampleSize(){
        return 1024;
    }

};

class H264:public VideoCodec{
    public:
    int getFrameRate(){
        return 30;
    }
};

class MP3:public AudioCodec{
    public:
    int getFrameSampleSize(){
        return 1152;
    }
};

class H265:public VideoCodec{
    public:
    int getFrameRate(){
        return 60;
    }
};

class CodecFactory{
    public:
    virtual shared_ptr<AudioCodec> createAudioCodec()=0;
    virtual shared_ptr<VideoCodec> createVideoCodec()=0;
};

class LeightWeightCodec:public CodecFactory{
    public:
    shared_ptr<AudioCodec> createAudioCodec(){
        return make_shared<AAC>();
    }
    shared_ptr<VideoCodec> createVideoCodec(){
        return make_shared<H264>();
    }

};

class HighQualityCodec:public CodecFactory{
     public:
    shared_ptr<AudioCodec> createAudioCodec(){
        return make_shared<MP3>();
    }
    shared_ptr<VideoCodec> createVideoCodec(){
        return make_shared<H265>();
    }
};

int main(){
    shared_ptr<CodecFactory> high_quality_codec=make_shared<LeightWeightCodec>();
  shared_ptr<AudioCodec> mp3_codec=high_quality_codec->createAudioCodec();
  shared_ptr<VideoCodec> h265_codec=high_quality_codec->createVideoCodec();
  cout<<"Frame size of mp3 codec="<<mp3_codec->getFrameSampleSize()<<endl;
  cout<<"Frame size of h265 codec="<<h265_codec->getFrameRate()<<endl;

   shared_ptr<CodecFactory> low_quality_codec=make_shared<HighQualityCodec>();
  shared_ptr<AudioCodec> aac_codec=low_quality_codec->createAudioCodec();
  shared_ptr<VideoCodec> h264_codec=low_quality_codec->createVideoCodec();
  cout<<"Frame size of aac codec="<<aac_codec->getFrameSampleSize()<<endl;
  cout<<"Frame size of h264 codec="<<h264_codec->getFrameRate()<<endl;

}