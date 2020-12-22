#ifndef MUSICOBJECT_H
#define MUSICOBJECT_H
#include <QString>


class musicObject
{
public:
    musicObject();

private:
    QString song_name;
    QString singer_name;
    QString singers_feat;
    QString song_language;
    QString song_releasedate;

public:
    QString get_song_name();
    QString get_singer_name();
    QString get_singers_feat();
    QString get_song_language();
    QString get_song_releasedate();

    void set_song_name(QString so_n);
    void set_singer_name(QString si_n);
    void set_singers_feat(QString so_f);
    void set_song_language(QString so_l);
    void set_song_releasedate(QString re_d);
};

#endif // MUSICOBJECT_H
