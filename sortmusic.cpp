#include "sortmusic.h"
#include <musicobject.h>
#include <QString>

sortMusic::sortMusic(){}
void sortMusic::swap_musicObjects(musicObject &obj1, musicObject &obj2)
{
    QString t=obj1.get_song_name();
    obj1.set_song_name(obj2.get_song_name());
    obj2.set_song_name(t);

    QString e=obj1.get_singer_name();
    obj1.set_singer_name(obj2.get_singer_name());
    obj2.set_singer_name(e);

    QString f=obj1.get_singers_feat();
    obj1.set_singers_feat(obj2.get_singers_feat());
    obj2.set_singers_feat(f);

    QString l=obj1.get_song_language();
    obj1.set_song_language(obj2.get_song_language());
    obj2.set_song_language(l);

    QString o=obj1.get_song_releasedate();
    obj1.set_song_releasedate(obj2.get_song_releasedate());
    obj2.set_song_releasedate(o);
}

void sortMusic::sort_by(QVector<musicObject> &music_List, int sort_Index)
{
    switch (sort_Index) {
    case 0:
        for(int i=0;i<music_List.size();i++){
            for(int j=0;j<music_List.size();j++){
             if(music_List[i].get_song_releasedate().toUpper()>music_List[j].get_song_releasedate().toUpper()){
                 swap_musicObjects(music_List[i],music_List[j]);
             }
            }
        }
        break;
    case 1:
        for(int i=0;i<music_List.size();i++){
            for(int j=0;j<music_List.size();j++){
             if(music_List[i].get_song_releasedate().toUpper()<music_List[j].get_song_releasedate().toUpper()){
                 swap_musicObjects(music_List[i],music_List[j]);
             }
            }
        }
        break;
    case 2:
        for(int i=0;i<music_List.size();i++){
            for(int j=0;j<music_List.size();j++){
             if(music_List[i].get_song_name().toUpper()>music_List[j].get_song_name().toUpper()){
                 swap_musicObjects(music_List[i],music_List[j]);
             }
            }
        }
        break;
    case 3:
        for(int i=0;i<music_List.size();i++){
            for(int j=0;j<music_List.size();j++){
             if(music_List[i].get_song_name().toUpper()<music_List[j].get_song_name().toUpper()){
                 swap_musicObjects(music_List[i],music_List[j]);
             }
            }
        }
        break;
    case 4:
        for(int i=0;i<music_List.size();i++){
            for(int j=0;j<music_List.size();j++){
             if(music_List[i].get_song_language().toUpper()<music_List[j].get_song_language().toUpper()){
                 swap_musicObjects(music_List[i],music_List[j]);
             }
            }
        }
        break;
    case 5:
        for(int i=0;i<music_List.size();i++){
            for(int j=0;j<music_List.size();j++){
             if(music_List[i].get_song_language().toUpper()>music_List[j].get_song_language().toUpper()){
                 swap_musicObjects(music_List[i],music_List[j]);
             }
            }
        }
        break;
    case 6:
        for(int i=0;i<music_List.size();i++){
            for(int j=0;j<music_List.size();j++){
             if(music_List[i].get_singer_name().toUpper()<music_List[j].get_singer_name().toUpper()){
                 swap_musicObjects(music_List[i],music_List[j]);
             }
            }
        }
        break;
    case 7:
        for(int i=0;i<music_List.size();i++){
            for(int j=0;j<music_List.size();j++){
             if(music_List[i].get_singer_name().toUpper()>music_List[j].get_singer_name().toUpper()){
                 swap_musicObjects(music_List[i],music_List[j]);
             }
            }
        }
        break;
    }
}

