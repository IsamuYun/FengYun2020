//Cracked by Roath
inherit ROOM;

int block_cmd(string);
void create ()
{
  set ("short", "������");
  set ("long", @LONG


������ʦΪ���ķ�����������Ƶķ����ң���ϰ�����񹦵���ó�
�����������������뾡�κΰ취���κλ������������ƣ�����ķ���
������Ӱ����ˣ���Ҫ��ΪӰ�����ݶ������ˣ������Ƿ�����......

LONG);

  set("exits", ([ /* sizeof() == 4 */
    "south" : "/d/city/kezhan",
  
]));
  set("objects", ([ /* sizeof() == 2 */
  
]));
set("no_time", 1);
set("freeze", 1);
  set("no_fight", 1);
set("chat_room",1);
  set("no_magic", 1);
  set("no_upgrade_age",1);

  setup();
  call_other("/obj/board/idle_b", "???");
}

int block_cmd(string args)
{
string verb;
verb = query_verb();

    // if (verb == "bian") return 1; // by mon 7/15
    if (verb == "xiudao") return 1;
    if (verb == "exert") return 1;
    return 0;
}
