#include<iostream>
using namespace std;


class VideoSegment{
    public:
    int segment_id;
    int duration;
    int resolution;
    string codec;
    VideoSegment* next;
    bool isPlayed;
   
    VideoSegment(int id , int dur , int res , string cod){
        segment_id=id;
        duration=dur;
        resolution=res;
        codec=cod;
        isPlayed=false;
        next=nullptr;
    }

};


class VideoStreamer{
    VideoSegment* head;
    VideoSegment* tail;

    public:
    VideoStreamer(){
        head=nullptr;
        tail=nullptr;
    }
    bool isEmpty(){
        if(!head) return true;
        return false;
    }
    void AddSegment(int segment_id , int dur, int resolution , string codec){
         VideoSegment* newVid=new VideoSegment(segment_id , dur , resolution , codec);
        if(isEmpty()){
            head=newVid;
            tail=head;
            return;
        }
        tail->next=newVid;
        tail=tail->next;


    }

    void playSegment(){
        if(isEmpty()){
            return;
        }
        VideoSegment* temp=head;
        while(temp->isPlayed){
            temp=temp->next;
        }
        cout<<"Current Video Segment: "<<endl;
        cout<<"Segment ID: "<<temp->segment_id<<endl;
        cout<<"Segment Duration: "<<temp->duration<<endl;
        cout<<"Segment Resolution: "<<temp->resolution<<endl;
        cout<<"Segment Codec: "<<temp->codec<<endl;
        temp->isPlayed=true;




    }
    void showBuffer(){
        if(isEmpty()){
            cout<<"No videos found"<<endl;
            return;
        }
        VideoSegment* temp=head;
        while(temp->isPlayed){
            temp=temp->next;
        }
        cout<<"Videos for upcoming playback: "<<endl;
        cout<<"======================================="<<endl;
        while(temp){
           
            cout<<"Segment ID: "<<temp->segment_id<<endl;
        cout<<"Segment Duration: "<<temp->duration<<endl;
        cout<<"Segment Resolution: "<<temp->resolution<<endl;
        cout<<"Segment Codec: "<<temp->codec<<endl;
        cout<<"==========================================="<<endl;
        
        temp=temp->next;
            

        }
    }

};


int main(){
    //Create video streamer Object
    VideoStreamer videostreamer;
    //add 5 videos
    videostreamer.AddSegment(1,20,650,"mp4");
        videostreamer.AddSegment(2,31,650,"mp3");
    videostreamer.AddSegment(3,25,968,"mp4");
        videostreamer.AddSegment(4,30,144,"mp4");
            videostreamer.AddSegment(5,20,650,"mp1");

            //display buffer 
            videostreamer.showBuffer();

            //play 2 videos
            
            cout<<"Played these 2 videos: "<<endl;
            videostreamer.playSegment();
            cout<<endl;
            videostreamer.playSegment();
            cout<<endl;

            //now remaining buffer
            videostreamer.showBuffer();





}

