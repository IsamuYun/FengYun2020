// feishi.c
// 编程：中山大学  张三丰（Micro）----Micro_Liang@Hotmail.Com

inherit BULLETIN_BOARD;

void create()
{
        set_name("飞氏集团员工档案册", ({ "book" }) );
        set("location", "/d/feishijituan/6_danganshi");
        set("board_id", "feishi2");
        set("long", "这是飞氏集团记录员工档案的地方。\n" );
        setup();
        set("capacity", 100);                    // 容量为30张留言（通常是30张）
        replace_program(BULLETIN_BOARD);
}
