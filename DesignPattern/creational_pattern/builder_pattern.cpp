#include <iostream>
#include <cstring>
#include <memory>
using namespace std;
class MediaFile{
    bool is_audio=false;
    bool is_video=false;
    char *  audio_codec="";
    char * video_codec="";
    char * container="";
    public:
    void setIsAudio(bool is_image){
        this->is_audio=is_image;
    }
    
    void setIsVideo(bool is_video){
        this->is_video=is_video;
    }

    void setAudioCodec(char * audio_codec){
        this->audio_codec=new char [strlen(audio_codec)+1];
        strcpy(this->audio_codec,audio_codec);
    }

    void setVideoCodec(char * video_codec){
          this->video_codec=new char [strlen(video_codec)+1];
        strcpy(this->video_codec,video_codec);
    }

    void setContainer(char * container){
          this->container=new char [strlen(container)+1];
        strcpy(this->container,container);
    }

    void display(){
        cout<<"is_audio:"<<is_audio<<endl;
        cout<<"is_video:"<<is_video<<endl;
        cout<<"audio_codec:"<<audio_codec<<endl;
        cout<<"video_codec:"<<video_codec<<endl;
        cout<<"container:"<<container<<endl;
    }
    
};

class MediaFileBuilder{
    public:
    virtual void buildIsAudio()=0;
    virtual void buildIsVideo()=0;
    virtual void buildAudioCodec()=0;
    virtual void buildVideoCodec()=0;
    virtual void buildContainer()=0;
    virtual MediaFile build()=0;

};

class OpusCodecBuilder:public MediaFileBuilder{
    private:
    shared_ptr<MediaFile> media_file;
    public:
    OpusCodecBuilder(){
        media_file=make_shared<MediaFile>();
    }

    void buildIsAudio(){
        media_file->setIsAudio(true);
    }

    void buildIsVideo(){
        media_file->setIsVideo(false);
    }

    void buildAudioCodec(){
        media_file->setAudioCodec("opus");
    }

    void buildVideoCodec(){
        media_file->setVideoCodec("None");
    }

    void buildContainer(){
        media_file->setContainer("opus");
    }

    MediaFile build(){
        return *media_file;
    }
        
};

class MediaFileDirector{
    public:
    MediaFile constrcutMediaFile(OpusCodecBuilder &builder){
        builder.buildIsAudio();
        // builder.buildVideoCodec();
        // builder.buildIsImage();
        // builder.buildContainer();
        return builder.build();

    }
};

int main(){
    OpusCodecBuilder opus_builder;
    MediaFileDirector director;
    MediaFile media_file=director.constrcutMediaFile(opus_builder);
    media_file.display();
    return 0;
}