// lianzhi.c by Tiandi 20071211
#include <ansi.h>

int main(object me, string arg)
{
        int lv,tili,tili_cost,stamp,clv,exp,bdamage;
        string name,ctype,newfile,filename,id,timestamp,cname;
        object ob1,ob2,ob;
        id = me->query("id");
        lv = (int)me->query("lifearmor");
        exp = me->query("lifearmor_exp");
        if (lv < 1)
        return notify_fail("你还不会这项生活技能。\n");

        name = me->query("name");
        tili = (int)me->query("lifetili");

        if( me->is_busy() )
                    return notify_fail("你上一个动作还没有完成！\n");
        if(! environment(me)->query("makearmor") )
                    return notify_fail("炼制物品必须在布铺才行才可以进行。\n");
        if( me->is_fighting() )
                    return notify_fail("战斗中炼制？你厉害！\n");
        if(!arg || sscanf(arg,"%s %d",ctype,clv) != 2)
                     return notify_fail("请输入正确的格式，详细请看help lianzhi。\n");
        if ( clv > lv)
                    return notify_fail("你想要炼制这个级别的防具，还得再磨练磨练。\n");
        if ( clv > 10 || clv<1)
                    return notify_fail("炼制防具的等级只有1-10。\n");
        tili_cost = 50*clv;
		tili_cost = tili_cost /10*(10-me->query("save_for_armor"));
        if( me->query("lifetili") < tili_cost )
                    return notify_fail("活力不够。\n");
        ob1 = present("duan book",me);
        if (!ob1) return notify_fail("缺少防具炼制用的制作指南书。\n");
        if(!ob1->query("for_create_armor")) return notify_fail("你想鱼目混珠？\n");
        if(ob1->query("for_create_armor") < (int)clv)
                    return notify_fail("这本制造指南书还不足以炼制出如此高级的防具。\n");
        ob2 = present("old iron",me);
        if (!ob2) return notify_fail("缺少防具炼制用的生铁。\n");
         if(!ob2->query("for_create_armor")&&!ob2->query("for_create_weapon")) return notify_fail("你想鱼目混珠？\n");
        if(ob2->query("for_create_armor") < (int)clv)
                    return notify_fail("这块材料还不足以炼制出如此高级的防具。\n");
         if(ob1->query("mtype")!= ctype)
                   return notify_fail("这本制作书不能炼制出这类防具。\n");
        seteuid(ROOT_UID);
        me->set("lifetili",tili-tili_cost);
        switch( ctype ) {
                    case "cloth":
                               newfile = read_file("/obj/armors/duancloth.c");
                              switch (clv) {
                                       case 1:
                                        newfile = replace_string( newfile, "描述","一件由" + name + "炼制而成的傲云衫。\n");
                                        exp = exp + 1;
                                        cname = "傲云衫";
                                        break;
                                        case 2:
                                        newfile = replace_string( newfile, "描述","一件由" + name + "炼制而成的轻云和服。棉布织就的长袍。\n");
                                        cname = HIW"轻云和服"NOR;
                                        exp = exp + 2;
                                        break;
                                        case 3:
                                        newfile = replace_string( newfile, "描述","一件由" + name + "炼制而成的狂沙劲衫。参杂着不少沙粒而成。\n");
                                        cname = MAG"狂沙劲衫"NOR;
                                        exp = exp + 3;
                                        break;
                                        case 4:
                                        newfile = replace_string( newfile, "描述","一件由" + name + "炼制而成的叶纹袄，图案华丽，质地精致的长袍，有很强的防御力 。\n");
                                        cname =HIG"叶纹袄"NOR;
                                        exp = exp + 4;
                                        break;
                                        case 5:
                                        newfile = replace_string( newfile, "描述","一件由" + name + "炼制而成的夜隐甲。紫金锻造的战甲，华贵且有着极强的防御力。\n");
                                        cname = RED"夜隐甲"NOR;
                                        exp = exp + 5;
                                        break;
                                        case 6:
                                        newfile = replace_string( newfile, "描述","一件由" + name + "炼制而成的天璇轻衣。白金制作的战甲穿在身上显得英姿飒爽。\n");
                                        cname = YEL"天璇轻衣"NOR;
                                        exp = exp + 6;
                                        break;
                                        case 7:
                                        newfile = replace_string( newfile, "描述","一件由" + name + "炼制而成的瑜玉战铠。传说中的瑜玉打造而成的盔甲，虽表面布满裂痕实际坚硬无比。\n");
                                        cname = CYN"瑜玉战铠"NOR;
                                        exp = exp + 7;
                                        break;
                                        case 8:
                                        newfile = replace_string( newfile, "描述","一件由" + name + "炼制而成的麒麟战甲。由麒麟之角提炼而成。\n");
                                        cname = HIY"麒麟战甲"NOR;
                                        exp = exp + 8;
                                        break;
                                        case 9:
                                        newfile = replace_string( newfile, "描述","一件由" + name + "炼制而成的玄皿魔袍。是黄毛老魔穿戴的防具。\n");
                                        cname = HIR"玄皿魔袍"NOR;
                                        exp = exp + 9;
                                        break;
                                        case 10:
                                        newfile = replace_string( newfile, "描述","一件由" + name + "炼制而成的修罗披风。天神与修罗作战时的专用装备，防护效果可想而知。\n");
                                        cname =HIC "修罗披风"NOR;
                                        exp = exp + 10;
                                        break;
                                        default:
                                        break;
                                        }
                               break;
                    case "head":
                               newfile = read_file("/obj/armors/duanhead.c");
                               switch (clv) {
                                        case 1:
                                        newfile = replace_string( newfile, "描述","一顶由" + name + "炼制而成的麻布头巾，普普通通。\n");
                                        exp = exp + 1;
                                        cname = "麻布头巾";
                                        break;
                                        case 2:
                                        newfile = replace_string( newfile, "描述","一顶由" + name + "炼制而成的厚棉头巾，效果比麻布的要好点。\n");
                                        cname = HIW"厚棉头巾"NOR;
                                        exp = exp + 2;
                                        break;
                                        case 3:
                                        newfile = replace_string( newfile, "描述","一顶由" + name + "炼制而成的无边帽，没有帽沿的帽子。\n");
                                        cname = MAG"无边帽"NOR;
                                        exp = exp + 3;
                                        break;
                                        case 4:
                                        newfile = replace_string( newfile, "描述","一顶由" + name + "炼制而成的锦绣帽，锦绣添花，十分名贵。\n");
                                        cname =HIG"锦绣帽"NOR;
                                        exp = exp + 4;
                                        break;
                                        case 5:
                                        newfile = replace_string( newfile, "描述","一顶由" + name + "炼制而成的向阳帽，它的一面总朝着太阳。\n");
                                        cname = RED"向阳帽"NOR;
                                        exp = exp + 5;
                                        break;
                                        case 6:
                                        newfile = replace_string( newfile, "描述","一顶由" + name + "炼制而成的黔首皮帽，略显智者的味道。\n");
                                        cname = YEL"黔首皮帽"NOR;
                                        exp = exp + 6;
                                        break;
                                        case 7:
                                        newfile = replace_string( newfile, "描述","一顶由" + name + "炼制而成的零花箍，飘叶零花般的一顶箍子。\n");
                                        cname = CYN"零花箍"NOR;
                                        exp = exp + 7;
                                        break;
                                        case 8:
                                        newfile = replace_string( newfile, "描述","一顶由" + name + "炼制而成的神皮帽，不知道用什么皮制作的。\n");
                                        cname = HIY"神皮帽"NOR;
                                        exp = exp + 8;
                                        break;
                                        case 9:
                                        newfile = replace_string( newfile, "描述","一顶由" + name + "炼制而成的凤羽冠，制作材料有凤凰的羽毛。\n");
                                        cname = HIR"凤羽冠"NOR;
                                        exp = exp + 9;
                                        break;
                                        case 10:
                                        newfile = replace_string( newfile, "描述","一顶由" + name + "炼制而成的龙麟冠，由龙的鳞片提炼出来。\n");
                                        cname =HIC "龙麟冠"NOR;
                                        exp = exp + 10;
                                        break;
                                        default:
                                        break;
                                        }
                               break;
                    case "neck":
                               newfile = read_file("/obj/armors/duanneck.c");
                              switch (clv) {
                                       case 1:
                                        newfile = replace_string( newfile, "描述","一条由" + name + "炼制而成的护身项链。\n");
                                        exp = exp + 1;
                                        cname = "护身项链";
                                        break;
                                        case 2:
                                        newfile = replace_string( newfile, "描述","一条由" + name + "炼制而成的双色彩链，红黄相映。\n");
                                        cname = HIW"双色彩链"NOR;
                                        exp = exp + 2;
                                        break;
                                        case 3:
                                        newfile = replace_string( newfile, "描述","一条由" + name + "炼制而成的玫瑰链，看上去像一朵玫瑰。\n");
                                        cname = MAG"玫瑰链"NOR;
                                        exp = exp + 3;
                                        break;
                                        case 4:
                                        newfile = replace_string( newfile, "描述","一条由" + name + "炼制而成的神木珠，散发出木头的清香 。\n");
                                        cname =HIG"神木珠"NOR;
                                        exp = exp + 4;
                                        break;
                                        case 5:
                                        newfile = replace_string( newfile, "描述","一条由" + name + "炼制而成的笑傲江湖。沧海一声笑，滔滔两岸潮。\n");
                                        cname = RED"笑傲江湖"NOR;
                                        exp = exp + 5;
                                        break;
                                        case 6:
                                        newfile = replace_string( newfile, "描述","一条由" + name + "炼制而成的漂渺法珠。细细的绳带托着一颗洁白的珠子。\n");
                                        cname = YEL"漂渺法珠"NOR;
                                        exp = exp + 6;
                                        break;
                                        case 7:
                                        newfile = replace_string( newfile, "描述","一条由" + name + "炼制而成的灵月仙舞。给人带来灵气。\n");
                                        cname = CYN"灵月仙舞"NOR;
                                        exp = exp + 7;
                                        break;
                                        case 8:
                                        newfile = replace_string( newfile, "描述","一条由" + name + "炼制而成的碧水铃。碧绿的珠子，却像极了铃铛。\n");
                                        cname = HIY"碧水铃"NOR;
                                        exp = exp + 8;
                                        break;
                                        case 9:
                                        newfile = replace_string( newfile, "描述","一条由" + name + "炼制而成的乾坤镜。传说可以看尽天下一切。\n");
                                        cname = HIR"乾坤镜"NOR;
                                        exp = exp + 9;
                                        break;
                                        case 10:
                                        newfile = replace_string( newfile, "描述","一条由" + name + "炼制而成的祥云之风。来历不详的神秘饰物，佩带在身上有极强的作用。\n");
                                        cname =HIC "祥云之风"NOR;
                                        exp = exp + 10;
                                        break;
                                        default:
                                        break;
                                        }
                               break; 
                    case "boots":
                              newfile = read_file("/obj/armors/duanboots.c");
                              switch (clv) {
                                       case 1:
                                        newfile = replace_string( newfile, "描述","一双由" + name + "炼制而成的羊皮靴。\n");
                                        exp = exp + 1;
                                        cname = "羊皮靴";
                                        break;
                                        case 2:
                                        newfile = replace_string( newfile, "描述","一双由" + name + "炼制而成的牛皮靴，牛皮制成。\n");
                                        cname = HIW"牛皮靴"NOR;
                                        exp = exp + 2;
                                        break;
                                        case 3:
                                        newfile = replace_string( newfile, "描述","一双由" + name + "炼制而成的神步鞋。能加快使用者的移动速度。\n");
                                        cname = MAG"神步鞋"NOR;
                                        exp = exp + 3;
                                        break;
                                        case 4:
                                        newfile = replace_string( newfile, "描述","一双由" + name + "炼制而成的神行跨龙，非常轻便的靴子，走起路来飞快 。\n");
                                        cname =HIG"神行跨龙"NOR;
                                        exp = exp + 4;
                                        break;
                                        case 5:
                                        newfile = replace_string( newfile, "描述","一双由" + name + "炼制而成的侠客靴。江湖中成名的人都曾穿过。\n");
                                        cname = RED"侠客靴"NOR;
                                        exp = exp + 5;
                                        break;
                                        case 6:
                                        newfile = replace_string( newfile, "描述","一双由" + name + "炼制而成的追日靴，有一日千里之效果。\n");
                                        cname = YEL"追日靴"NOR;
                                        exp = exp + 6;
                                        break;
                                        case 7:
                                        newfile = replace_string( newfile, "描述","一双由" + name + "炼制而成的战月神履。能更好的发挥使用者的能力。\n");
                                        cname = CYN"战月神履"NOR;
                                        exp = exp + 7;
                                        break;
                                        case 8:
                                        newfile = replace_string( newfile, "描述","一双由" + name + "炼制而成的龙虎战履。一只由龙皮，一只由虎皮制成。\n");
                                        cname = HIY"龙虎战履"NOR;
                                        exp = exp + 8;
                                        break;
                                        case 9:
                                        newfile = replace_string( newfile, "描述","一双由" + name + "炼制而成的踏雪无痕。穿之幻影如风，踏雪无痕。\n");
                                        cname = HIR"踏雪无痕"NOR;
                                        exp = exp + 9;
                                        break;
                                        case 10:
                                        newfile = replace_string( newfile, "描述","一双由" + name + "炼制而成的凌空虚渡。穿之凌空之行，万里皆行。\n");
                                        cname =HIC "凌空虚渡"NOR;
                                        exp = exp + 10;
                                        break;
                                        default:
                                        break;
                                        }
                               break;   
                    case "finger":
                              newfile = read_file("/obj/armors/duanfinger.c");
                              switch (clv) {
                                       case 1:
                                        newfile = replace_string( newfile, "描述","一枚由" + name + "炼制而成的铁戒。\n");
                                        exp = exp + 1;
                                        cname = "铁戒";
                                        break;
                                        case 2:
                                        newfile = replace_string( newfile, "描述","一枚由" + name + "炼制而成的梅花戒，呈现梅花状。\n");
                                        cname = HIW"梅花戒"NOR;
                                        exp = exp + 2;
                                        break;
                                        case 3:
                                        newfile = replace_string( newfile, "描述","一枚由" + name + "炼制而成的如痴戒指。如痴如醉，不绝人世。\n");
                                        cname = MAG"如痴戒指"NOR;
                                        exp = exp + 3;
                                        break;
                                        case 4:
                                        newfile = replace_string( newfile, "描述","一枚由" + name + "炼制而成的虎戒，能听见有虎吟的声音 。\n");
                                        cname =HIG"虎戒"NOR;
                                        exp = exp + 4;
                                        break;
                                        case 5:
                                        newfile = replace_string( newfile, "描述","一枚由" + name + "炼制而成的梦灭戒指。梦晓心灭，与世无争。\n");
                                        cname = RED"梦灭戒指"NOR;
                                        exp = exp + 5;
                                        break;
                                        case 6:
                                        newfile = replace_string( newfile, "描述","一枚由" + name + "炼制而成的绝情戒，无情之人才配拥有。\n");
                                        cname = YEL"绝情戒"NOR;
                                        exp = exp + 6;
                                        break;
                                        case 7:
                                        newfile = replace_string( newfile, "描述","一枚由" + name + "炼制而成的霹雳雷霆。戴上它能带来好运气。\n");
                                        cname = CYN"霹雳雷霆"NOR;
                                        exp = exp + 7;
                                        break;
                                        case 8:
                                        newfile = replace_string( newfile, "描述","一枚由" + name + "炼制而成的道道。没有人知道它的来源。\n");
                                        cname = HIY"道道"NOR;
                                        exp = exp + 8;
                                        break;
                                        case 9:
                                        newfile = replace_string( newfile, "描述","一枚由" + name + "炼制而成的七彩飞石。彩虹过后才能显现出它的威力。\n");
                                        cname = HIR"七彩飞石"NOR;
                                        exp = exp + 9;
                                        break;
                                        case 10:
                                        newfile = replace_string( newfile, "描述","一枚由" + name + "炼制而成的龙神戒指，王者的象征。\n");
                                        cname =HIC "龙神戒指"NOR;
                                        exp = exp + 10;
                                        break;
                                        default:
                                        break;
                                        }
                               break;  
                    case "waist":
                              newfile = read_file("/obj/armors/duanwaist.c");
                              switch (clv) {
                                       case 1:
                                        newfile = replace_string( newfile, "描述","一根由" + name + "炼制而成的细腰带。\n");
                                        exp = exp + 1;
                                        cname = "细腰带";
                                        break;
                                        case 2:
                                        newfile = replace_string( newfile, "描述","一根由" + name + "炼制而成的粗腰带，很普通。\n");
                                        cname = HIW"粗腰带"NOR;
                                        exp = exp + 2;
                                        break;
                                        case 3:
                                        newfile = replace_string( newfile, "描述","一根由" + name + "炼制而成的麻布腰带。效果还不错。\n");
                                        cname = MAG"麻布腰带"NOR;
                                        exp = exp + 3;
                                        break;
                                        case 4:
                                        newfile = replace_string( newfile, "描述","一根由" + name + "炼制而成的蛇皮腰带，用蛇皮制成的。\n");
                                        cname =HIG"蛇皮腰带"NOR;
                                        exp = exp + 4;
                                        break;
                                        case 5:
                                        newfile = replace_string( newfile, "描述","一根由" + name + "炼制而成的白鹿腰带。具有防寒的效果。\n");
                                        cname = RED"白鹿腰带"NOR;
                                        exp = exp + 5;
                                        break;
                                        case 6:
                                        newfile = replace_string( newfile, "描述","一根由" + name + "炼制而成的虎皮腰带，很有气势的装备。\n");
                                        cname = YEL"虎皮腰带"NOR;
                                        exp = exp + 6;
                                        break;
                                        case 7:
                                        newfile = replace_string( newfile, "描述","一根由" + name + "炼制而成的摄魂布。简单的一块布却能有很大的功效。\n");
                                        cname = CYN"摄魂布"NOR;
                                        exp = exp + 7;
                                        break;
                                        case 8:
                                        newfile = replace_string( newfile, "描述","一根由" + name + "炼制而成的帝王腰带。有福之人才能得到它。\n");
                                        cname = HIY"帝王腰带"NOR;
                                        exp = exp + 8;
                                        break;
                                        case 9:
                                        newfile = replace_string( newfile, "描述","一根由" + name + "炼制而成的蛮山带。蛮人常常带着它打仗。\n");
                                        cname = HIR"蛮山带"NOR;
                                        exp = exp + 9;
                                        break;
                                        case 10:
                                        newfile = replace_string( newfile, "描述","一根由" + name + "炼制而成的幻云仙带，能最大功效的发挥它的能力。\n");
                                        cname =HIC "幻云仙带"NOR;
                                        exp = exp + 10;
                                        break;
                                        default:
                                        break;
                                        }
                               break; 
                    case "shield":
                              newfile = read_file("/obj/armors/duanshield.c");
                              switch (clv) {
                                       case 1:
                                        newfile = replace_string( newfile, "描述","一个由" + name + "炼制而成的铁盾。\n");
                                        exp = exp + 1;
                                        cname = "铁盾";
                                        break;
                                        case 2:
                                        newfile = replace_string( newfile, "描述","一个由" + name + "炼制而成的钢盾，防御效果很差。\n");
                                        cname = HIW"钢盾"NOR;
                                        exp = exp + 2;
                                        break;
                                        case 3:
                                        newfile = replace_string( newfile, "描述","一个由" + name + "炼制而成的玄铁盾。防御效果很小。\n");
                                        cname = MAG"玄铁盾"NOR;
                                        exp = exp + 3;
                                        break;
                                        case 4:
                                        newfile = replace_string( newfile, "描述","一个由" + name + "炼制而成的大名盾，用大名蟹的壳制成。\n");
                                        cname =HIG"大名盾"NOR;
                                        exp = exp + 4;
                                        break;
                                        case 5:
                                        newfile = replace_string( newfile, "描述","一个由" + name + "炼制而成的蛇蜥盾。具有很好的防御力。\n");
                                        cname = RED"蛇蜥盾"NOR;
                                        exp = exp + 5;
                                        break;
                                        case 6:
                                        newfile = replace_string( newfile, "描述","一个由" + name + "炼制而成的珊瑚盾，有很高的韧性。\n");
                                        cname = YEL"珊瑚盾"NOR;
                                        exp = exp + 6;
                                        break;
                                        case 7:
                                        newfile = replace_string( newfile, "描述","一个由" + name + "炼制而成的天云战盾。防御力极强的盾牌。\n");
                                        cname = CYN"天云战盾"NOR;
                                        exp = exp + 7;
                                        break;
                                        case 8:
                                        newfile = replace_string( newfile, "描述","一个由" + name + "炼制而成的幽灵盾。有缘人才能得之。\n");
                                        cname = HIY"幽灵盾"NOR;
                                        exp = exp + 8;
                                        break;
                                        case 9:
                                        newfile = replace_string( newfile, "描述","一个由" + name + "炼制而成的蓝岚盾。散发出淡淡的蓝光。\n");
                                        cname = HIR"蓝岚盾"NOR;
                                        exp = exp + 9;
                                        break;
                                        case 10:
                                        newfile = replace_string( newfile, "描述","一个由" + name + "炼制而成的元成霸盾，盾中的王者。\n");
                                        cname =HIC "元成霸盾"NOR;
                                        exp = exp + 10;
                                        break;
                                        default:
                                        break;
                                        }
                               break; 
                    case "wrists":
                              newfile = read_file("/obj/armors/duanwrists.c");
                              switch (clv) {
                                       case 1:
                                        newfile = replace_string( newfile, "描述","一对由" + name + "炼制而成的钢铁护腕。\n");
                                        exp = exp + 1;
                                        cname = "钢铁护腕";
                                        break;
                                        case 2:
                                        newfile = replace_string( newfile, "描述","一对由" + name + "炼制而成的勇者护腕，勇者的象征。\n");
                                        cname = HIW"勇者护腕"NOR;
                                        exp = exp + 2;
                                        break;
                                        case 3:
                                        newfile = replace_string( newfile, "描述","一对由" + name + "炼制而成的天青刺。明亮而修长，更适合姑娘佩戴。\n");
                                        cname = MAG"天青刺"NOR;
                                        exp = exp + 3;
                                        break;
                                        case 4:
                                        newfile = replace_string( newfile, "描述","一对由" + name + "炼制而成的苗峰护腕，坚固如峰。\n");
                                        cname =HIG"苗峰护腕"NOR;
                                        exp = exp + 4;
                                        break;
                                        case 5:
                                        newfile = replace_string( newfile, "描述","一对由" + name + "炼制而成的百战神风。战斗中不可缺少的装备。\n");
                                        cname = RED"百战神风"NOR;
                                        exp = exp + 5;
                                        break;
                                        case 6:
                                        newfile = replace_string( newfile, "描述","一对由" + name + "炼制而成的美人护腕，每一只上都雕刻着一位绝世佳人。\n");
                                        cname = YEL"美人护腕"NOR;
                                        exp = exp + 6;
                                        break;
                                        case 7:
                                        newfile = replace_string( newfile, "描述","一对由" + name + "炼制而成的喧天柄。让人感到心情十分沉重。\n");
                                        cname = CYN"喧天柄"NOR;
                                        exp = exp + 7;
                                        break;
                                        case 8:
                                        newfile = replace_string( newfile, "描述","一对由" + name + "炼制而成的魉单。似乎有鬼魅在其中发出声响。\n");
                                        cname = HIY"魉单"NOR;
                                        exp = exp + 8;
                                        break;
                                        case 9:
                                        newfile = replace_string( newfile, "描述","一对由" + name + "炼制而成的侠骨道风护腕。令人生出敬佩之心。\n");
                                        cname = HIR"侠骨道风护腕"NOR;
                                        exp = exp + 9;
                                        break;
                                        case 10:
                                        newfile = replace_string( newfile, "描述","一只由" + name + "炼制而成的侠骨柔风护腕，只有一代大侠才配持有此物。\n");
                                        cname =HIC "侠骨柔风护腕"NOR;
                                        exp = exp + 10;
                                        break;
                                        default:
                                        break;
                                        }
                               break; 

							   default:
                               return notify_fail("这种防具你还不会炼制。\n");
                    }
        timestamp = sprintf("%c%c%c%c%c%c%d",
        'a'+random(20),'a'+random(20),'a'+random(20),'a'+random(20),'a'+random(20),
        'z',time());
       stamp=time();
       newfile = replace_string( newfile, "自制的", cname);
        newfile = replace_string( newfile, "order", ctype);
         newfile = replace_string( newfile, "fengyun", id);
         newfile = replace_string( newfile, "STAMP",timestamp);

      //  filename =  DATA_DIR+ "self/" +timestamp + ".c";
	  //  filename改成玩家目录下的，避免以后read时候缓慢
		filename = DATA_DIR+"user/" + id[0..0] + "/" + id + "/" +timestamp + ".c";
        if( !write_file(filename, newfile,1))
                    return 0;
        ob = new(filename);
        if(ob2->query("equipped")) {ob2->unequip(); me->reset_action();}
        ob2->move(environment(me));
        bdamage = 100*(clv-1)+20+ random(80);
        ob->set("weight",ob2->query_weight());
        ob->set("rigidity",ob2->query("rigidity"));
		if (ctype == "cloth")
		{
			ob->set("armor_prop/armor",bdamage);
			ob->set("base_armor",bdamage);
		}
		else if (ctype == "head")
		{
			ob->set("armor_prop/marmor",bdamage/10*7);
			ob->set("armor_prop/mdamage",bdamage/10*9);
		}
		else if (ctype == "neck")
		{
			ob->set("armor_prop/addforce",random(bdamage/10)+clv);
			ob->set("armor_prop/dodge",bdamage);
		}
		else if (ctype == "boots")
		{
			ob->set("armor_prop/move",bdamage);
			ob->set("armor_prop/heavyhit",random(bdamage/100)+clv/2);
		}
		else if (ctype == "finger")
		{
			ob->set("armor_prop/addkee",random(bdamage/10)+clv*10);
			ob->set("armor_prop/addmana",random(bdamage/10)+clv*10);
		}
		else if (ctype == "waist")
		{
			ob->set("armor_prop/addeffkee",bdamage*2);
			ob->set("armor_prop/against",random(bdamage/100)+clv);
		}
		else if (ctype == "wrists")
		{
			ob->set("armor_prop/attack",bdamage*3/2);
			ob->set("armor_prop/mattack",bdamage/4);
		}
		else if (ctype == "shield")
		{
			ob->set("armor_prop/armor",bdamage/2);
			ob->set("base_armor",bdamage/2);
		}
        ob->set("limited_lv",clv*10);
        ob->set("value",clv*10000);
		ob->set("abradability",500);
		if (ctype != "cloth")
	{
			ob->set("level",20);
			ob->set("leveled",20);
	}
		if(!random(10))
			ob->add("abradability",clv*50);
		if(!random(10))
			ob->set("armor_prop/strength",random(clv*5)+1);
		if(!random(10))
			ob->set("armor_prop/courage",random(clv*5)+1);
		if(!random(10))
			ob->set("armor_prop/intelligence",random(clv*5)+1);
		if(!random(10))
			ob->set("armor_prop/spirituality",random(clv*5)+1);
		if(!random(10))
			ob->set("armor_prop/composure",random(clv*5)+1);
		if(!random(10))
			ob->set("armor_prop/personality",random(clv*5)+1);
		if(!random(10))
			ob->set("armor_prop/constitution",random(clv*5)+1);
		if(!random(10))
			ob->set("armor_prop/karma",random(clv*5)+1);
		if(!random(10))
			ob->set("armor_prop/agility",random(clv*5)+1);
		if(!random(10))
			ob->set("armor_prop/durability",random(clv*5)+1);
		if(!random(10))
			ob->set("armor_prop/flexibility",random(clv*5)+1);
		if(!random(10))
			ob->set("armor_prop/tolerance",random(clv*5)+1);
        ob->save();
        ob->restore();
        if(ob->move(me)){
        me->add("created_armor",1);
        me->start_busy(1);
        write("你将身上的"+ob2->name()+"扔进了打铁炉中，按照"+ob1->name()+"中所讲述的方法进行炼制，一阵折腾之后一"+ob->query("unit")+
        ob->name()+"出现在你眼前。\n");
        me->set("lifearmor_exp",exp);
        destruct(ob2);
        destruct(ob1);
		seteuid(getuid());
        return 1;
        }
}

int help(object me)
{
write(@HELP
指令格式 : lianzhi 类别 防具等级

这个指令让你利用你的生活技能炼制出各类防具
前提是你必须具有炼制需要的材料，而且炼制的
等级要高于防具等级。
炼制类别有
	头    head
	身    cloth
	脚    boots
	戒指  finger
	腰    waist
	盾    shield
	手腕  wrists
	项链  neck

HELP
    );
return 1;
}
