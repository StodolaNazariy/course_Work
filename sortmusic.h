#ifndef SORTMUSIC_H
#define SORTMUSIC_H
#include <musicobject.h>
#include <QVector>

class sortMusic
{
public:
    sortMusic();

private:

public:
    static void swap_musicObjects(musicObject &obj1, musicObject &obj2 );
    void sort_by(QVector<musicObject> &music_List, int sort_index);

};

#endif // SORTMUSIC_H
