//gift's hongbao by tiandi 20071229
#include <ansi.h>;
inherit ITEM;
string *gifts = ({
"/obj/weapons/banzhi",
"/obj/weapons/banzhi2",
"/obj/weapons/banzhi3",
"/obj/weapons/banzhi4",
"/obj/weapons/banzhi5",
"/obj/weapons/banzhi6",
"/obj/weapons/banzhi7",
"/obj/weapons/banzhi8",
"/obj/weapons/banzhi9",
"/obj/weapons/banzhi",
"/obj/weapons/banzhi2",
"/obj/weapons/banzhi3",
"/obj/weapons/banzhi4",
"/obj/weapons/banzhi5",
"/obj/weapons/banzhi6",
"/obj/weapons/banzhi7",
"/obj/weapons/banzhi8",
"/obj/weapons/banzhi9",
"/obj/weapons/banzhi",
"/obj/weapons/banzhi2",
"/obj/weapons/banzhi3",
"/obj/weapons/banzhi4",
"/obj/weapons/banzhi5",
"/obj/weapons/banzhi6",
"/obj/weapons/banzhi7",
"/obj/weapons/banzhi8",
"/obj/weapons/banzhi9",
"/obj/weapons/banzhi",
"/obj/weapons/banzhi2",
"/obj/weapons/banzhi3",
"/obj/weapons/banzhi4",
"/obj/weapons/banzhi5",
"/obj/weapons/banzhi6",
"/obj/weapons/banzhi7",
"/obj/weapons/banzhi8",
"/obj/weapons/banzhi9",
"/obj/weapons/banzhi",
"/obj/weapons/banzhi2",
"/obj/weapons/banzhi3",
"/obj/weapons/banzhi4",
"/obj/weapons/banzhi5",
"/obj/weapons/banzhi6",
"/obj/weapons/banzhi7",
"/obj/weapons/banzhi8",
"/obj/weapons/banzhi9",
"/obj/weapons/banzhi",
"/obj/weapons/banzhi2",
"/obj/weapons/banzhi3",
"/obj/weapons/banzhi4",
"/obj/weapons/banzhi5",
"/obj/weapons/banzhi6",
"/obj/weapons/banzhi7",
"/obj/weapons/banzhi8",
"/obj/weapons/banzhi9",
"/obj/weapons/banzhi",
"/obj/weapons/banzhi2",
"/obj/weapons/banzhi3",
"/obj/weapons/banzhi4",
"/obj/weapons/banzhi5",
"/obj/weapons/banzhi6",
"/obj/weapons/banzhi7",
"/obj/weapons/banzhi8",
"/obj/weapons/banzhi9",
"/obj/weapons/banzhi",
"/obj/weapons/banzhi2",
"/obj/weapons/banzhi3",
"/obj/weapons/banzhi4",
"/obj/weapons/banzhi5",
"/obj/weapons/banzhi6",
"/obj/weapons/banzhi7",
"/obj/weapons/banzhi8",
"/obj/weapons/banzhi9",
"/obj/weapons/swordbook",
"/obj/weapons/swordbook2",
"/obj/weapons/swordbook3",
"/obj/weapons/swordbook4",
"/obj/weapons/swordbook5",
"/obj/weapons/swordbook6",
"/obj/weapons/swordbook7",
"/obj/weapons/swordbook8",
"/obj/weapons/swordbook9",
"/obj/weapons/bladebook6",
"/obj/weapons/bladebook7",
"/obj/weapons/bladebook8",
"/obj/weapons/bladebook9",
"/obj/weapons/bladebook5",
"/obj/weapons/bladebook4",
"/obj/weapons/bladebook3",
"/obj/weapons/bladebook2",
"/obj/weapons/bladebook",
"/obj/weapons/staffbook",
"/obj/weapons/staffbook2",
"/obj/weapons/staffbook3",
"/obj/weapons/staffbook4",
"/obj/weapons/staffbook5",
"/obj/weapons/staffbook6",
"/obj/weapons/staffbook7",
"/obj/weapons/staffbook8",
"/obj/weapons/staffbook9",
"/obj/weapons/hammerbook",
"/obj/weapons/hammerbook2",
"/obj/weapons/hammerbook3",
"/obj/weapons/hammerbook4",
"/obj/weapons/hammerbook5",
"/obj/weapons/hammerbook6",
"/obj/weapons/hammerbook7",
"/obj/weapons/hammerbook8",
"/obj/weapons/hammerbook9",
"/obj/weapons/ringbook",
"/obj/weapons/ringbook2",
"/obj/weapons/ringbook3",
"/obj/weapons/ringbook4",
"/obj/weapons/ringbook5",
"/obj/weapons/ringbook6",
"/obj/weapons/ringbook7",
"/obj/weapons/ringbook8",
"/obj/weapons/ringbook9",
"/obj/armors/headbook",
"/obj/armors/headbook2",
"/obj/armors/headbook3",
"/obj/armors/headbook4",
"/obj/armors/headbook5",
"/obj/armors/headbook6",
"/obj/armors/headbook7",
"/obj/armors/headbook8",
"/obj/armors/headbook9",
"/obj/armors/clothbook",
"/obj/armors/clothbook2",
"/obj/armors/clothbook3",
"/obj/armors/clothbook4",
"/obj/armors/clothbook5",
"/obj/armors/clothbook6",
"/obj/armors/clothbook7",
"/obj/armors/clothbook8",
"/obj/armors/clothbook9",
"/obj/armors/neckbook",
"/obj/armors/neckbook2",
"/obj/armors/neckbook3",
"/obj/armors/neckbook4",
"/obj/armors/neckbook5",
"/obj/armors/neckbook6",
"/obj/armors/neckbook7",
"/obj/armors/neckbook8",
"/obj/armors/neckbook9",
"/obj/armors/bootsbook",
"/obj/armors/bootsbook2",
"/obj/armors/bootsbook3",
"/obj/armors/bootsbook4",
"/obj/armors/bootsbook5",
"/obj/armors/bootsbook6",
"/obj/armors/bootsbook7",
"/obj/armors/bootsbook8",
"/obj/armors/bootsbook9",
"/obj/armors/waistbook",
"/obj/armors/waistbook2",
"/obj/armors/waistbook3",
"/obj/armors/waistbook4",
"/obj/armors/waistbook5",
"/obj/armors/waistbook6",
"/obj/armors/waistbook7",
"/obj/armors/waistbook8",
"/obj/armors/waistbook9",
"/obj/armors/wristsbook",
"/obj/armors/wristsbook2",
"/obj/armors/wristsbook3",
"/obj/armors/wristsbook4",
"/obj/armors/wristsbook5",
"/obj/armors/wristsbook6",
"/obj/armors/wristsbook7",
"/obj/armors/wristsbook8",
"/obj/armors/wristsbook9",
"/obj/armors/fingerbook",
"/obj/armors/fingerbook2",
"/obj/armors/fingerbook3",
"/obj/armors/fingerbook4",
"/obj/armors/fingerbook5",
"/obj/armors/fingerbook6",
"/obj/armors/fingerbook7",
"/obj/armors/fingerbook8",
"/obj/armors/fingerbook9",
"/obj/armors/shieldbook",
"/obj/armors/shieldbook2",
"/obj/armors/shieldbook3",
"/obj/armors/shieldbook4",
"/obj/armors/shieldbook5",
"/obj/armors/shieldbook6",
"/obj/armors/shieldbook7",
"/obj/armors/shieldbook8",
"/obj/armors/shieldbook9",
"/obj/food/cj",
"/obj/food/cj2",
"/obj/food/cj3",
"/obj/food/cj4",
"/obj/food/cj5",
"/obj/food/cj6",
"/obj/food/cj7",
"/obj/food/cj8",
"/obj/food/cj9",
"/obj/food/dan1",
"/obj/food/dan2",
"/obj/food/dan3",
"/obj/food/dan4",
"/obj/food/dan5",
"/obj/food/dan6",
"/obj/food/dan7",
"/obj/food/dan8",
"/obj/food/dan9",
});
void create()
{
set_name( HIR"忠义盒"NOR, ({ "tie-box" }));;
set_weight(10);
set("value", 0);
set("unit", "个");
set("long", "这是完成忠义任务所得到的锦盒。你可以打开(open)看看。\n");
setup();
}
void init()
{
        add_action("do_open", "open");
}

int do_open(string arg)
{
        object me,gift_give;
        int i;
        me = this_player();
        if( !arg || arg=="" ) return 0;
        if( arg=="tie-box" || arg =="box" ) {
                   
                   gift_give = new(gifts[random(sizeof(gifts))]);
                   gift_give->move(me);
	      tell_object(me,"\n\n怒发冲冠，凭栏处，潇潇雨歇。抬望眼，仰天长啸，壮怀激烈。\n三十功名尘与土，八千里路云和月。莫等闲，白了少年头，空悲切。
\n\n靖康耻，犹未雪；臣子恨，何时灭！驾长车踏破贺兰山缺。\n壮志饥餐胡虏肉，笑谈渴饮匈奴血。待从头，收拾旧山河，朝天阙。");
                   tell_object(me,HIW"\n你打开忠义盒，恭喜您额外获得"+gift_give->query("name")+HIW"。\n"NOR);
                   destruct(this_object());
                   return 1;
                   }
        return 1;
        }
