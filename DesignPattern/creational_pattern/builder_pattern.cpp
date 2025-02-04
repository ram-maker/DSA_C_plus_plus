#include <iostream>
#include <cstring>
#include <memory>
using namespace std;

class MediaFile {
    bool is_audio;
    bool is_video;
    char* audio_codec;
    char* video_codec;
    char* container;

public:
    // Constructor initializes pointers to nullptr to prevent garbage values
    MediaFile() : audio_codec(nullptr), video_codec(nullptr), container(nullptr), is_audio(false), is_video(false) {}

    void setIsAudio(bool is_audio) {
        this->is_audio = is_audio;
    }

    void setIsVideo(bool is_video) {
        this->is_video = is_video;
    }

    void setAudioCodec(const char* audio_codec) {
        this->audio_codec = new char[strlen(audio_codec) + 1];
        strcpy(this->audio_codec, audio_codec);
    }

    void setVideoCodec(const char* video_codec) {
        this->video_codec = new char[strlen(video_codec) + 1];
        strcpy(this->video_codec, video_codec);
    }

    void setContainer(const char* container) {
        this->container = new char[strlen(container) + 1];
        strcpy(this->container, container);
    }

    void display() const {
        cout << "is_audio: " << is_audio << endl;
        cout << "is_video: " << is_video << endl;
        cout << "audio_codec: " << (audio_codec ? audio_codec : "null") << endl;
        cout << "video_codec: " << (video_codec ? video_codec : "null") << endl;
        cout << "container: " << (container ? container : "null") << endl;
    }

};

class MediaFileBuilder {
public:
    virtual MediaFileBuilder& buildIsAudio() = 0;
    virtual MediaFileBuilder& buildIsVideo() = 0;
    virtual MediaFileBuilder& buildAudioCodec() = 0;
    virtual MediaFileBuilder& buildVideoCodec() = 0;
    virtual MediaFileBuilder& buildContainer() = 0;
    virtual MediaFile build() = 0;
};

class OpusCodecBuilder : public MediaFileBuilder {
private:
    shared_ptr<MediaFile> media_file;

public:
    OpusCodecBuilder() {
        media_file = make_shared<MediaFile>();
    }

    MediaFileBuilder& buildIsAudio() override {
        media_file->setIsAudio(true);
        return *this;  // return the builder itself for chaining
    }

    MediaFileBuilder& buildIsVideo() override {
        media_file->setIsVideo(false);
        return *this;  // return the builder itself for chaining
    }

    MediaFileBuilder& buildAudioCodec() override {
        media_file->setAudioCodec("opus");
        return *this;  // return the builder itself for chaining
    }

    MediaFileBuilder& buildVideoCodec() override {
        media_file->setVideoCodec("None");
        return *this;  // return the builder itself for chaining
    }

    MediaFileBuilder& buildContainer() override {
        media_file->setContainer("opus");
        return *this;  // return the builder itself for chaining
    }

    MediaFile build() override {
        return *media_file;
    }
};

class MediaFileDirector {
public:
    MediaFile constructMediaFile(MediaFileBuilder& builder) {
        return builder.buildAudioCodec()
            //    .buildIsAudio()
               .buildContainer()
               .build();
        
    }
};

int main() {
    OpusCodecBuilder opus_builder;
    MediaFileDirector director;
    MediaFile media_file = director.constructMediaFile(opus_builder);
    media_file.display();
    return 0;
}
