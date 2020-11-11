// Room: /d/wiz/wizroom.c

inherit ROOM;

int block_cmd();

void create ()
{
  set ("short", "巫师工作报告简报厅");
  set ("long", @LONG

这里是巫师报告自己工作进度的简报室，如果你有工作做或
改动了什么文件，最好常常到这里更新你的工作进度，如果
你改动文件后没有声明，被查出后要严格处理,如果太久没有
看到你的工作进度报告,大巫师们会以为以没事做而指派工作
给你，要是你仍然不理，也有可能会被假设成已经放弃巫师的
工作而降回玩家身分。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"jobroom",
]));

  set("wiz_board",1);

  setup();
  call_other("/obj/board/wizard_l.c", "???");
}

void init()
{   
        if (!wizardp(this_player()))
          add_action("block_cmd","",1);   
}

int block_cmd()
{
       string verb = query_verb();

       if (verb=="say") return 0; //allow say
       if (verb=="chat") return 0;
       if (verb=="quit") return 0;
       if (verb=="look") return 0;
       return 1;
}


