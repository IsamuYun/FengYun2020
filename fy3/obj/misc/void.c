// void.c
// From SZ-ES2
// 修改：中山大学  张三丰（Micro）----Micro_Liang@Hotmail.Com

inherit ROOM;

void create()
{
        set("short","虚无世界");
        set("long",@LONG

    这里就是传说中的虚无世界。你似乎看到四周一片白茫茫的，仔细一
看，却发现什么也没有，甚至连刚才的白也不复存在。你摇了摇头, 却忍
不住想起你那些可亲可敬的朋友们，你恨不得马上飞到他们的身边，见上
他们一面。
LONG
        );

        set("exits", ([
                "down" : "/d/center/guangchang",
        ]));

        setup();
        replace_program(ROOM);
}
