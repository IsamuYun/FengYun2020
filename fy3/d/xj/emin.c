#include <globals.h>
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
ȫ��Ϊ������׿���������ֳ��չ���������������Ǭ¡��ʮ���꣬
��һʽ�Ļһ�ɫש���ɣ������Ͼ���������Բ�����Σ��´���ϸ������
��ש����װ��������ơ�ˮ���ơ������İ껨�ơ�ɽ�Ƶȼ���ͼ�ι�ʮ
���֡��������ڲ�ͬ�߶Ⱥͷ��򿪳�ʮ������ڡ����쾫�£���Ϊ׳�ۡ�
�����ڲ��ṹ��û�л�ʯ��Ҳû��ľ�ϣ�����ש������ʮ�༶��������
�������ȿɼӹ������ֿ������ʵ�ֱ��������
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "westdown" : __DIR__"tulufan",
  "eastdown" : __DIR__"butao",
  "southeast" : __DIR__"gumu",
]));
        set("objects", ([
                __DIR__"npc/ghost" :2,
                        ]) );
	set("no_pk",1);
	set("no_spells",1);
	set("no_magic",1);
        set("outdoors", "xinjiang");
        set("coor/x",-1060);
	set("coor/y",1030);
	set("coor/z",0);
	setup();
}
