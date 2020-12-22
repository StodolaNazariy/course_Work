#include "musicobject.h"

musicObject::musicObject(){}

QString musicObject::get_song_name()
{
    return this->song_name;
}
QString musicObject::get_singer_name()
{
    return this->singer_name;
}
QString musicObject::get_singers_feat()
{
    return this->singers_feat;
}
QString musicObject::get_song_language()
{
    return this->song_language;
}
QString musicObject::get_song_releasedate()
{
    return this->song_releasedate;
}
void musicObject::set_song_name(QString so_n)
{
    this->song_name=so_n;
}
void musicObject::set_singer_name(QString si_n)
{
    this->singer_name=si_n;
}
void musicObject::set_singers_feat(QString so_f)
{
    this->singers_feat=so_f;
}
void musicObject::set_song_language(QString so_l)
{
    this->song_language=so_l;
}
void musicObject::set_song_releasedate(QString re_d)
{
    this->song_releasedate=re_d;
}
