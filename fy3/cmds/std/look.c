//edit by tiandi 2008.6.11
#include <room.h>
#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;
int look_room(object me, object env);
int look_item(object me, object obj);
int look_living(object me, object obj);
int look_room_item(object me, string arg);
string getper(object me, object obj);
string tough_level(int power);
string gettof(object me, object obj);
string getdam(object me, object obj);
string *tough_level_desc = ({
BLU"不堪一击"NOR,BLU"毫不足虑"NOR,BLU"不知所以"NOR,BLU"新学乍练"NOR,BLU"勉勉强强"NOR,
BLU"初窥门径"NOR,BLU"初出茅庐"NOR,BLU"略知一二"NOR,BLU"普普通通"NOR,BLU"平平淡淡"NOR,

HIB"平淡无奇"NOR,HIB"粗通皮毛"NOR,HIB"半生不熟"NOR,HIB"马马虎虎"NOR,HIB"略有小成"NOR,
HIB"已有小成"NOR,HIB"渐入佳境"NOR,HIB"登堂入室"NOR,HIB"挥洒自如"NOR,HIB"融会贯通"NOR, 

CYN"心领神会"NOR,CYN"炉火纯青"NOR,CYN"了然於胸"NOR,CYN"略有大成"NOR,CYN"已有大成"NOR,
CYN"豁然贯通"NOR,CYN"出类拔萃"NOR,CYN"无可匹敌"NOR,CYN"技冠群雄"NOR,CYN"神乎其技"NOR,

HIC"出神入化"NOR,HIC"非同凡响"NOR,HIC"傲视群雄"NOR,HIC"登峰造极"NOR,HIC"无与伦比"NOR,
HIC"所向披靡"NOR,HIC"一代宗师"NOR,HIC"精深奥妙"NOR,HIC"神功盖世"NOR,HIC"举世无双"NOR,

HIR"惊世骇俗"NOR,HIR"撼天动地"NOR,HIR"震古铄今"NOR,HIR"超凡入圣"NOR,HIR"威镇寰宇"NOR,
HIR"空前绝后"NOR,HIR"天人合一"NOR,HIR"深藏不露"NOR,HIR"横扫江湖"NOR,HIR"深不可测"NOR,

HIY"威不可挡"NOR,HIY"技惊四座"NOR,HIR"强绝天下"NOR,HIY"威镇武林"NOR,HIR"前无古人"NOR,
HIY"返璞归真"NOR,HIY"独步天下"NOR,HIY"旷古绝伦"NOR,HIY"天下无敌"NOR,HIY"天下第一"NOR,
});
string *heavy_level_desc= ({
        "极轻",
        "很轻",
        "不重",
        "不轻",
        "很重",
        "极重"  
});
void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        object obj;
        int result;

        if( !arg ) result = look_room(me, environment(me));
        else if( (obj = present(arg, me)) || (obj = present(arg, environment(me)))) {
                if( obj->is_character() ) result = look_living(me, obj);
                else result = look_item(me, obj);
        } else result = look_room_item(me, arg);
        return result;
}

int look_room(object me, object env)
{
        int i;
        object *inv;
        mapping exits,quest;
        string str, *dirs;
        if( !env ) {
                write("你的四周灰蒙蒙地一片，什麽也没有。\n");
                return 1;
        }
        str ="\n";
        str += sprintf( "%s - %s\n    %s%s",
                env->query("short"),
                wizardp(me)? file_name(env)+sprintf(" - (%d,%d,%d)",env->query("coor/x"),
                env->query("coor/y"),env->query("coor/z")): "",
                env->query("long"),
                env->query("outdoors")? NATURE_D->outdoor_room_description() : "" );
	// add by tiandi for job	
	
	if (quest =  me->query("tiequest"))
	{
		if ((string)env->query("short") == quest["quest"])
		{
	 	 str +=HIG"    你突然发现这里的风景果然和阿铁所述的一样，于是静下心来慢慢欣赏。\n"NOR;
		   call_out("auto_perform", random(60), me); 
		}
	}
        if( mapp(exits = env->query("exits")) ) {
                dirs = keys(exits);
                for(i=0; i<sizeof(dirs); i++)
        if( (int)env->query_door(dirs[i], "status") & DOOR_CLOSED )
                                dirs[i] = 0;
                dirs -= ({ 0 });
                if( sizeof(dirs)==0 )
                        str += "    这里没有任何明显的出路。\n";
                else if( sizeof(dirs)==1 )
                        str += "    这里唯一的出口是 " + BOLD + dirs[0] + NOR + "。\n";
                else
                        str += sprintf("    这里明显的出口是 " + BOLD + "%s" + NOR + " 和 " + BOLD + "%s" + NOR + "。\n",
                                implode(dirs[0..sizeof(dirs)-2], "、"), dirs[sizeof(dirs)-1]);
        }
        else str += "    这里没有任何明显的出路。\n";

        inv = all_inventory(env);
        for(i=0; i<sizeof(inv); i++) {
                if( inv[i]==me ) continue;
               if( inv[i]->query("no_shown")) continue;
                if( !me->visible(inv[i]) ) continue;
	  if (inv[i]->query("inquiry"))
		  str +=HIY" ?"NOR;
	  else
		  str += "  ";

	  if (inv[i]->query_temp("in_trade"))
		str +=inv[i]->short() + HIB "<摆摊中>" NOR"\n";
              else  if (inv[i]->is_busy() )
		str +=inv[i]->short() + HIY "<忙碌中>" NOR"\n";
	  else  if (inv[i]->query("statusnow"))
		str +=inv[i]->short() + HIY "<"+ inv[i]->query("statusnow")+">" NOR"\n";
	else
		str +=	inv[i]->short() + "\n";


        }
        write(str);
        return 1;
}

int look_item(object me, object obj)
{
        mixed *inv;
        string prep,line;
		printf(HIY"┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n"NOR);
		printf(HIY"   "NOR"%-60s",obj->long());

		if (obj->query("weapon_prop") || obj->query("armor_prop"))
		{
		printf(HIY"┠━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┨\n"NOR);
		line = sprintf(HIY"┃"HIR" 成长程度:%-10d 强化程度:%-10d 装备耐久:%-10d 等级需求:%-10d"HIY"┃\n"NOR,
			obj->query("level"),obj->query("leveled"),
			obj->query("abradability"),obj->query("limited_lv"));
		line += sprintf(HIY"┃"NOR" 物理命中:%-10d 物理伤害:%-10d 物理防御:%-10d 物理闪躲:%-10d"HIY"┃\n"NOR,
			obj->query("weapon_prop/attack")?obj->query("weapon_prop/attack"):obj->query("armor_prop/attack"),
			obj->query("weapon_prop/damage")?obj->query("weapon_prop/damage"):obj->query("armor_prop/damage"),
			obj->query("armor_prop/armor")?obj->query("armor_prop/armor"):obj->query("weapon_prop/armor"),
			obj->query("armor_prop/dodge")?obj->query("armor_prop/dodge"):obj->query("weapon_prop/armor"));
		line += sprintf(HIY"┃"NOR" 法术命中:%-10d 法术伤害:%-10d 法术防御:%-10d 法术闪躲:%-10d"HIY"┃\n"NOR,
			obj->query("weapon_prop/mattack")?obj->query("weapon_prop/mattack"):obj->query("armor_prop/mattack"),
			obj->query("weapon_prop/mdamage")?obj->query("weapon_prop/mdamage"):obj->query("armor_prop/mdamage"),
			obj->query("armor_prop/marmor")?obj->query("armor_prop/marmor"):obj->query("weapon_prop/marmor"),
			obj->query("armor_prop/mdodge")?obj->query("armor_prop/mdodge"):obj->query("weapon_prop/mdodge"));
		line += sprintf(HIY"┃"NOR" 力    量:%-10d 勇    气:%-10d 才    智:%-10d 灵    性:%-10d"HIY"┃\n"NOR,
			obj->query("weapon_prop/strength")?obj->query("weapon_prop/strength"):obj->query("armor_prop/strength"),
			obj->query("weapon_prop/courage")?obj->query("weapon_prop/courage"):obj->query("armor_prop/courage"),
			obj->query("weapon_prop/intelligence")?obj->query("weapon_prop/intelligence"):obj->query("armor_prop/intelligence"),
			obj->query("weapon_prop/spirituality")?obj->query("weapon_prop/strength"):obj->query("armor_prop/spirituality"));
		line += sprintf(HIY"┃"NOR" 定    力:%-10d 魅    力:%-10d 体    质:%-10d 运    气:%-10d"HIY"┃\n"NOR,
			obj->query("weapon_prop/composure")?obj->query("weapon_prop/composure"):obj->query("armor_prop/composure"),
			obj->query("weapon_prop/personality")?obj->query("weapon_prop/personality"):obj->query("armor_prop/personality"),
			obj->query("weapon_prop/constitution")?obj->query("weapon_prop/constitution"):obj->query("armor_prop/constitution"),
			obj->query("weapon_prop/karma")?obj->query("weapon_prop/karma"):obj->query("armor_prop/karma"));
		line += sprintf(HIY"┃"NOR" 速    度:%-10d 耐    力:%-10d 韧    性:%-10d 气    量:%-10d"HIY"┃\n"NOR,
			obj->query("weapon_prop/agility")?obj->query("weapon_prop/agility"):obj->query("armor_prop/agility"),
			obj->query("weapon_prop/durability")?obj->query("weapon_prop/durability"):obj->query("armor_prop/durability"),
			obj->query("weapon_prop/flexibility")?obj->query("weapon_prop/flexibility"):obj->query("armor_prop/flexibility"),
			obj->query("weapon_prop/tolerance")?obj->query("weapon_prop/tolerance"):obj->query("armor_prop/tolerance"));
		line += sprintf(HIY"┃"HIM" 气回:%-5d 法回:%-5d 内回:%-5d 血量:%-5d 暴率:%-5d 抗性:%-5d 灵巧:%-5d"HIY"   ┃\n"NOR,
			obj->query("armor_prop/addkee"),obj->query("armor_prop/addmana"),
			obj->query("armor_prop/addforce"),obj->query("armor_prop/addeffkee"),
			obj->query("armor_prop/heavyhit"),obj->query("armor_prop/against"),obj->query("armor_prop/move"));

		write(line);
		printf(HIY"┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n"NOR);
		}
		
	else
	printf(HIY"┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n"NOR);
        inv = all_inventory(obj);
        if( !obj->is_closed() && sizeof(inv)) {
                switch( (string)obj->query("prep") ) {
                        case "on":
                                prep = "上";
                                break;
                        case "under":
                                prep = "下";
                                break;
                        case "behind":
                                prep = "后";
                                break;
                        case "inside":
                                prep = "里";
                                break;
                        default:
                                prep = "里";
                                break;
                        }
                inv = map_array(inv, "inventory_look", this_object() );
                message("vision", sprintf("%s面有：\n  %s\n", prep,
                        implode(inv, "\n  ") ), me);
        }
        return 1;
}

string getper(object me, object obj)
{
        int per;
        int spi;
        int weight;
        string str;
        per = obj->query_per();
        spi = me->query_spi();
        if (spi>35) weight = 0;
        else weight = (int)(35 - spi)/4 ;
        if (random(10)>6) per = per - weight;
        else per = per + weight ;
                  if ((string) obj->query("gender") == "男性" || (string) obj->query("gender") == "无性")
        {
                   
                     if (per >=40) 
                        str =HIG"现在一派神人气度，仙风道骨，举止出尘。\n"NOR;
                if (per <= 39 && (per > 38))
                        str =HIG"现在神清气爽，骨格清奇，宛若仙人。\n"NOR;
                if (per <= 38 && (per > 37))
                        str =HIG"现在丰神俊朗，长身玉立，宛如玉树临风。\n"NOR;
                if (per <= 37 && (per > 36))
                        str =HIG"现在飘逸出尘，潇洒绝伦。\n"NOR;
                if (per <= 36 && (per > 35))
                        str =HIG"现在面如美玉，粉妆玉琢，俊美不凡。\n"NOR;
                if (per <= 35 && (per > 34))
                        str =HIG"现在丰神如玉，目似朗星，令人过目难忘。\n"NOR;
                if (per <= 34 && (per > 33))
                        str =HIY"现在粉面朱唇，身姿俊俏，举止风流无限。\n"NOR;
                if (per <= 33 && (per > 32))
                        str =HIY"现在双目如星，眉梢传情，所见者无不为之心动。\n"NOR;
                if (per <= 32 && (per > 31))
                        str =HIY"现在举动如行云游水，独蕴风情，吸引所有异性目光。\n"NOR;
                if (per <= 31 && (per > 30))
                        str =HIY"现在双眼光华莹润，透出摄人心魄的光芒。\n"NOR;
                if (per <= 30 && (per > 29))
                        str =HIY"生得英俊潇洒，风流倜傥。\n"NOR;
                if (per <= 29 && (per > 28))
                        str =MAG"生得目似点漆，高大挺俊，令人心动。\n"NOR;
                if (per <= 28 && (per > 27))
                        str =MAG"生得面若秋月，儒雅斯文，举止适度。\n"NOR;
                if (per <= 27 && (per > 26))
                        str =MAG"生得剑眉星目，英姿勃勃，仪表不凡。\n"NOR;
                if (per <= 26 && (per > 25))
                        str =MAG"生得满面浓髯，环眼豹鼻，威风凛凛，让人倾倒。\n"NOR;
                if (per <= 25 && (per > 24))
                        str =MAG"生得眉如双剑，眼如明星，英挺出众。\n"NOR;
                if (per <= 24 && (per > 23))
                        str =CYN"生得虎背熊腰，壮健有力，英姿勃发。\n"NOR;
                if (per <= 23 && (per > 22))
                        str =CYN"生得肤色白皙，红唇墨发，斯文有礼。\n"NOR;
                if (per <= 22 && (per > 21))
                        str =CYN"生得浓眉大眼，高大挺拔，气宇轩昂。\n"NOR;
                if (per <= 21 && (per > 20))
                        str =CYN"生得鼻直口方，线条分明，显出刚毅性格。\n"NOR;
                if (per <= 20 && (per > 19))
                        str =CYN"生得眉目清秀，端正大方，一表人才。\n"NOR;
                if (per <= 19 && (per > 18))
                        str =YEL"生得腰圆背厚，面阔口方，骨格不凡。\n"NOR;
                if (per <= 18 && (per > 17))
                        str =YEL"生得相貌平平，不会给人留下什么印相。\n"NOR;
                if (per <= 17 && (per > 16))
                        str =YEL"生得膀大腰圆，满脸横肉，恶形恶相。\n"NOR;
                if (per <= 16 && (per > 15))
                        str =YEL"生得獐头鼠须，让人一看就不生好感。\n"NOR;
                if (per <= 15 && (per > 14))
                        str =YEL"生得面颊深陷，瘦如枯骨，让人要发恶梦。\n"NOR;
                if (per <= 14 && (per > 13))
                        str =RED"生得肥头大耳，腹圆如鼓，手脚短粗，令人发笑。\n"NOR;
                if (per <= 13 && (per > 12))
                        str =RED"生得贼眉鼠眼，身高三尺，宛若猴状。\n"NOR;
                if (per <= 12 && (per > 11))
                        str =RED"生得面如桔皮，头肿如猪，让人不想再看第二眼。\n"NOR;
                if (per <= 11 && (per > 10))
                        str =RED"生得呲牙咧嘴，黑如锅底，奇丑无比。\n"NOR;
                if (per <= 10)
                        str =RED"生得眉歪眼斜，瘌头癣脚，不象人样。\n"NOR;
        }
        else
        {
            if ((string) obj->query("gender") == "女性")
            {
                if (per >=40) 
                        str =HIW"现在宛如玉雕冰塑，似梦似幻，已不再是凡间人物\n"NOR;
                if (per <= 39 && (per > 38))
                        str =HIG"现在美若天仙，不沾一丝烟尘。\n"NOR;
                if (per <= 38 && (per > 37))
                        str = HIG"现在灿若明霞，宝润如玉，恍如神妃仙子。\n"NOR;
                if (per <= 37 && (per > 36))
                        str =HIG"现在气质美如兰，才华馥比山，令人见之忘俗。\n"NOR;
                if (per <= 36 && (per > 35))
                        str =HIG"现在丰润嫩白，婴桃小口，眉目含情，仿佛太真重临。\n"NOR;
                if (per <= 35 && (per > 34))
                        str =HIG"现在鲜艳妩媚，袅娜风流，柔媚姣俏，粉光脂艳。\n"NOR;
                if (per <= 34 && (per > 33))
                        str =HIY"现在鬓若刀裁，眉如墨画，面如桃瓣，目若秋波。\n"NOR;
                if (per <= 33 && (per > 32))
                        str =HIY"现在凤眼柳眉，粉面含春，丹唇贝齿，转盼多情。\n"NOR;
                if (per <= 32 && (per > 31))
                        str =HIY"现在眉目如画，肌肤胜雪，真可谓闭月羞花。\n"NOR;
                if (per <= 31 && (per > 30))
                        str =HIY"现在娇若春花，媚如秋月，真的能沉鱼落雁。。\n"NOR;
                if (per <= 30 && (per > 29))
                        str =HIY"生得闲静如姣花照水，行动似弱柳扶风，体态万千。\n"NOR;
                if (per <= 29 && (per > 28))
                        str =MAG"生得娇小玲珑，宛如飞燕再世，楚楚动人。\n"NOR;
                if (per <= 28 && (per > 27))
                        str =MAG"生得鸭蛋秀脸，俊眼修眉，黑发如瀑，风情万种。\n"NOR;
                if (per <= 27 && (per > 26))
                        str =MAG"生得削肩细腰，身材苗条，娇媚动人，顾盼神飞。\n"NOR;
                if (per <= 26 && (per > 25))
                        str =MAG"生得丰胸细腰，妖娆多姿，让人一看就心跳不已。\n"NOR;
                if (per <= 25 && (per > 24))
                        str =MAG"生得粉嫩白至，如芍药笼烟，雾里看花。\n"NOR;
                if (per <= 24 && (per > 23))
                        str =CYN"生得腮凝新荔，目若秋水，千娇百媚。\n"NOR;
                if (per <= 23 && (per > 22))
                        str =CYN"生得鲜艳妍媚，肌肤莹透，引人遐思。\n"NOR;
                if (per <= 22 && (per > 21))
                        str =CYN"生得巧笑嫣然，宛约可人。\n"NOR;
                if (per <= 21 && (per > 20))
                        str =CYN"生得如梨花带露，清新秀丽。\n"NOR;
                if (per <= 20 && (per > 19))
                        str =CYN"生得风姿楚楚，明丽动人。\n"NOR;
                if (per <= 19 && (per > 18))
                        str =YEL"生得肌肤微丰，雅淡温宛，清新可人。\n"NOR;
                if (per <= 18 && (per > 17))
                        str =YEL"生得虽不标致，倒也白净，有些动人之处。\n"NOR;
                if (per <= 17 && (per > 16))
                        str =YEL"生得身材瘦小，肌肤无光，两眼无神。\n"NOR;
                if (per <= 16 && (per > 15))
                        str = YEL"生得干黄枯瘦，脸色腊黄，毫无女人味。\n"NOR;
                if (per <= 15 && (per > 14))
                        str =YEL"生得满脸疙瘩，皮色粗黑，丑陋不堪。\n"NOR;
                if (per <= 14 && (per > 13))
                        str =RED"生得一嘴大暴牙，让人一看就没好感。\n"NOR;
                if (per <= 13 && (per > 12))
                        str =RED"生得眼小如豆，眉毛稀疏，手如猴爪，不成人样。\n"NOR;
                if (per <= 12 && (per > 11))
                        str =RED"生得八字眉，三角眼，鸡皮黄发，让人一见就想吐。\n"NOR;
                if (per <= 11 && (per > 10))
                        str =RED"生得歪鼻斜眼，脸色灰败，直如鬼怪一般。\n"NOR;
                 if (per <=10) 
                        str =RED"生得丑如无盐，状如夜叉，女人长成这样真是人生悲剧。\n"NOR;
         }
    }
        if( !str) str="";
        return str;
}
string gettof(object me, object ob)
{
        object weapon;
        string skill_type,parry_type;
        int attack_points;
		/*调整为等级 by tiandi
        if( objectp(weapon = ob->query_temp("weapon")) )
        {
                skill_type = weapon->query("skill_type");
                parry_type = "parry";
        }
        else
        {
                skill_type = "unarmed";
                parry_type = "unarmed";
        }

        attack_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_ATTACK);
		*/
        return  tough_level(ob->query("level"));
}
int look_living(object me, object obj)
{
        string str, limb_status, pro;
        mixed *inv;
        mapping my_fam, fam;

        if( me!=obj )
                message("vision", me->name() + "正盯著你看，不知道打些什麽主意。\n", obj);
        str ="\n"; 
        str += obj->long();
        pro = (obj==me) ? gender_self(obj->query("gender")) : gender_pronoun(obj->query("gender"));
        if( (string)obj->query("race")=="人类"
        &&      intp(obj->query("age")) )
                if(userp(obj))
                str +=  sprintf("%s看起来象%s多岁的%s人。\n", pro, chinese_number(obj->query("age") / 10 * 10),
                                obj->query("national"));
                else
                str += sprintf("%s看起来约%s多岁。\n", pro, chinese_number(obj->query("age") / 10 * 10));
                str+=getper(me,obj);
                str +=sprintf("武功看起来好象");
                str+=gettof(me,obj);
                str += sprintf("，");
                str +=sprintf("出手似乎");
                str +=getdam(me,obj);
                str += sprintf("。\n");
        if( obj!=me
        &&      mapp(fam = obj->query("family"))
        &&      mapp(my_fam = me->query("family")) 
        &&      fam["family_name"] == my_fam["family_name"] ) {
        
                if( fam["generation"]==my_fam["generation"] ) {
                        if( (string)obj->query("gender") == "男性" )
                                str += sprintf( pro + "是你的%s%s。\n",
                                        my_fam["master_id"] == fam["master_id"] ? "": "同门",
                                        my_fam["enter_time"] > fam["enter_time"] ? "师兄": "师弟");
                        else
                                str += sprintf( pro + "是你的%s%s。\n",
                                        my_fam["master_id"] == fam["master_id"] ? "": "同门",
                                        my_fam["enter_time"] > fam["enter_time"] ? "师姐": "师妹");
                } else if( fam["generation"] < my_fam["generation"] ) {
                        if( my_fam["master_id"] == obj->query("id") )
                                str += pro + "是你的师父。\n";
                        else if( my_fam["generation"] - fam["generation"] > 1 )
                                str += pro + "是你的同门长辈。\n";
                        else if( fam["enter_time"] < my_fam["enter_time"] )
                                str += pro + "是你的师伯。\n";
                        else
                                str += pro + "是你的师叔。\n";
                } else {
                        if( fam["generation"] - my_fam["generation"] > 1 )
                                str += pro + "是你的同门晚辈。\n";
                        else if( fam["master_id"] == me->query("id") )
                                str += pro + "是你的弟子。\n";
                        else
                                str += pro + "是你的师侄。\n";
                }
        }
        if(obj->query("prick") )
{
                                str += pro + RED"身上好象插了一枝血箭。\n"NOR;
}
        if(obj->query("id")==me->query("marry") )
        {
              if( (string)me->query("gender")=="女性" )
              {
                    str += sprintf("%s是你的丈夫。\n", pro);
              }
              else{
                    str += sprintf("%s是你的妻子。\n", pro);
              }
        }
        if (me->query("jiebai"))
        if (strsrch(me->query("jiebai"), obj->query("id")+">") >= 0)
        {
              if( obj->query("gender")=="女性" )
              {
                    if (obj->query("mud_age") > me->query("mud_age"))
                        str += sprintf("%s是你的义姐。\n", pro);
                    else
                        str += sprintf("%s是你的结义妹子。\n", pro);
              }
              else{
                    if (obj->query("mud_age") > me->query("mud_age"))
                        str += sprintf("%s是你的结义兄长。\n", pro);
                    else
                        str += sprintf("%s是你的义弟。\n", pro);
              }
        }

        if( obj->query("max_kee") )
                str += pro + COMBAT_D->eff_status_msg((int)obj->query("eff_kee") * 100 / (int)obj->query("max_kee")) + "\n";

        inv = all_inventory(obj);
        if( sizeof(inv) ) {
                inv = map_array(inv, "inventory_look", this_object(), obj->is_corpse()? 0 : 1 );
                inv -= ({ 0 });
                if( sizeof(inv) )
                        str += sprintf( obj->is_corpse() ? "%s的遗物有：\n%s\n" : "%s身上带著：\n%s\n",
                                pro, implode(inv, "\n") );
        }

        message("vision", str, me);

        if( obj!=me 
        &&      living(obj)
        &&      random((int)obj->query("bellicosity")/10) > (int)me->query_per() ) {
                write( obj->name() + HIR"突然转过头来瞪你一眼。\n"NOR);
                COMBAT_D->auto_fight(obj, me, "berserk");
        }

        return 1;
}

string inventory_look(object obj, int flag)
{
        string str;

        str = obj->short();
        if( obj->query("equipped") )
                str = HIC "  ★" NOR + str;
        else if( !flag )
                str = "    " + str;
        else
                return 0;

        return str;
}

int look_room_item(object me, string arg)
{
        object env;
        mapping item, exits;

        if( !objectp(env = environment(me)) )
                return notify_fail("这里只有灰蒙蒙地一片，什麽也没有。\n");

        if( mapp(item = env->query("item_desc")) && !undefinedp(item[arg]) ) {
                if( stringp(item[arg]) )
                        write(item[arg]);
                else if( functionp(item[arg]) )
                        write((string)(*item[arg])(me));
                        
                return 1;
        }
        if( mapp(exits = env->query("exits")) && !undefinedp(exits[arg]) ) {
                if( objectp(env = find_object(exits[arg])) )
                        look_room(me, env);
                else {
                        call_other(exits[arg], "???");
                        look_room(me, find_object(exits[arg]));
                }
                return 1;
        }
        return notify_fail("你要看什麽？\n");
}
string tough_level(int power)
{

        int lvl;
		power -= 1;
        if(power<1) power=0;
        lvl = to_int(power/2);
                        if( lvl >= sizeof(tough_level_desc) )
                                lvl = sizeof(tough_level_desc)-1;
                        return tough_level_desc[((int)lvl)];
}
string getdam(object me, object obj)
{

        int level;
        level = obj->query_temp("apply/damage");
        level = level / 50;
                        if( level >= sizeof(heavy_level_desc) )
                                level = sizeof(heavy_level_desc)-1;
                        return heavy_level_desc[((int)level)];
}
void auto_perform(object me) 
{ 
	object env,gift,gold;
	int reb,exp,ti,pot,score,doubletime,doubletype;
	mapping quest;
         env = environment(me);
	
	quest =  me->query("tiequest");
	//write("start"+env->query("short")+"\n"+quest["quest"]+"\n");
	if (quest && (string)env->query("short") == quest["quest"])
	{
	 	message_vision("\n\n你把"+(string)env->query("short") +"的景色尽收眼底，心情顿时舒畅了起来。\n",me);
		if ((int) me->query("tiequest_time") < time() )
    		       {
          			 tell_object(me,"很可惜，你未能及时完成任务。\n");
			return;
    		       }
      		    else
    		      {
 	        tell_object(me,"恭喜你！你又完成了一个忠义任务！\n");
	reb = me->query("reborned");
    exp = me->query("level");
	doubletime = me->query("doubletime");
	doubletype = (int)me->query("doubletype");
	ti = me->query_temp("tiejobtemp");
	exp = 100*exp;
	exp = exp + exp/10*ti;
	exp = exp + exp/5*reb;
	//write(exp+"/20000*"+ti);
	if (doubletime - time() > 0)
		exp = exp*(doubletype+1);
	exp = exp / 2;
	pot = exp / 7 * 4;
	score = reb+1;  

	me->add("combat_exp",exp);
	me->add("potential",pot);
    me->add("score",score);
  	tell_object(me,HIW"你被奖励了：\n" +
	chinese_number(exp) + "点实战经验\n"+
	chinese_number(pot) + "点潜能\n"+
	chinese_number(score)+"点评价\n" NOR);
	if (ti==10)
		{
		if ( me->query("level")>89)
				gift=new("/d/wiz/fyup/obj/hongbao5");
		else if ( me->query("level")>79)
				gift=new("/d/wiz/fyup/obj/hongbao4");
		else if ( me->query("level")>69)
				gift=new("/d/wiz/fyup/obj/hongbao3");
		else if ( me->query("level")>59)
				gift=new("/d/wiz/fyup/obj/hongbao2");
		else if ( me->query("level")>49)
				gift=new("/d/wiz/fyup/obj/hongbao1");	
		else gift=new("/d/wiz/fyup/obj/hongbao");
		gift->move(me);
		score = 60 + random(40);
		score = score + score/5*reb;
		gold=new("/obj/money/gold");
	    gold->set_amount(exp/100);
	    gold->move(me);
		me->add("score",score);
		me->add("combat_exp",exp);
		me->add("potential",pot);
  		tell_object(me,HIY"你被额外奖励了：\n" +
		chinese_number(exp) + "点实战经验\n"+
		chinese_number(pot) + "点潜能\n"+
		chinese_number(exp/100) + "两黄金\n"+
		chinese_number(score)+"点评价\n" NOR);
		tell_object(me,HIY"你的包裹好像重了一点。\n"NOR);
		}
	ti ++;
	if (!ti) ti = 1;
	if (ti >10) ti = 1;
	me->set_temp("tiejobtemp", ti );
          me->add("tiejob", 1 );
	me->set("tiequest",0);
		}

	}
	return;
} 
int help (object me)
{
        write(@HELP
指令格式: look [<物品>|<生物>|<方向>]
 
这个指令让你查看你所在的环境、某件物品、生物、或是方向。
 
HELP
);
        return 1;
}


