inherit ITEM;

void create()
{
        set_name("参观须知", ({ "paizi" }) );
        set_weight(500);
        set("no_get", 1);
        set("no_shown", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("prep", "on");
                set("unit", "张");
                set("long", "欢迎大家来这里做客，首先提醒大家，邀请信看过了吧！好，那大家就随便看看吧。
其实拿了东西也不是真的不能安全出去了，试试求饶（qiurao）！
以后这里要陆续增加一些娱乐设施。欢迎再次光临。\n");
                set("value", 1);
        }
}

int is_container()
{
return 1;
}
