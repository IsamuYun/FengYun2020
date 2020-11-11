//inventory.c
#include <ansi.h>
inherit F_CLEAN_UP;
object find_player(string target)
{
        int i;
        object *str;
        str=users();
        for (i=0;i<sizeof(str);i++)
                if (str[i]->query("id")==target)
                        return str[i];
        return 0;
}
int main(object me, string arg)
{
        int i,amount;
        object *inv, ob,obj;
        mapping my;
        string *str,leftw,rightw,neck,head,cloth,boots,finger,waist,shield,wrists;
        if( wizardp(me) && arg ) {
                ob = find_player(arg);
                if( !ob ) ob = find_living(arg);
                if( !ob ) ob = present(arg, environment(me));
        }
        if( !ob ) ob = me;
		if (ob->query_temp("left_hand"))
			leftw = ob->query_temp("left_hand")->query("name");
		else
			leftw = "无";
		if (ob->query_temp("right_hand"))
			rightw = ob->query_temp("right_hand")->query("name");
		else
			rightw = "无";
		if (ob->query_temp("armor/head"))
			head = ob->query_temp("armor/head")->query("name");
		else
			head = "无";
		if (ob->query_temp("armor/neck"))
			neck = ob->query_temp("armor/neck")->query("name");
		else
			neck = "无";
		if (ob->query_temp("armor/cloth"))
			cloth = ob->query_temp("armor/cloth")->query("name");
		else
			cloth = "无";
		if (ob->query_temp("armor/boots"))
			boots = ob->query_temp("armor/boots")->query("name");
		else
			boots = "无";
		if (ob->query_temp("armor/finger"))
			finger = ob->query_temp("armor/finger")->query("name");
		else
			finger = "无";
		if (ob->query_temp("armor/waist"))
			waist = ob->query_temp("armor/waist")->query("name");
		else
			waist = "无";
		if (ob->query_temp("armor/shield"))
			shield = ob->query_temp("armor/shield")->query("name");
		else
			shield = "无";
		if (ob->query_temp("armor/wrists"))
			wrists = ob->query_temp("armor/wrists")->query("name");
		else
			wrists = "无";
		printf(HIY"━━━━━━━  装备一览  ━━━━━━━━━━━━\n"NOR);
		printf("  左手：%-s  \t 右手：%-s  \n"NOR,leftw,rightw);
		printf("  头部：%-s  \t 项链：%-s  \n"NOR,head,neck);
		printf("  身体：%-s  \t 戒指：%-s  \n"NOR,cloth,finger);
		printf("  护腕：%-s  \t 腰带：%-s  \n"NOR,wrists,waist);
		printf("  鞋子：%-s  \t 盾牌：%-s  \n"NOR,boots,shield);
		printf(HIY"━━━━━━━━━━━━━━━━━━━━━━━━━\n"NOR);

        inv = all_inventory(ob);
        if( !sizeof(inv) ) {
                write((ob==me)? HIW"目前你身上没有任何东西。\n"NOR
                        : ob->name() + HIW"身上没有携带任何东西。\n"NOR);
                return 1;
        }
        obj=first_inventory(ob);
        arg="";
        while(obj){
                reset_eval_cost();
                if (obj->query("equipped")  || obj->query("money_id")){
arg+=sprintf("%s%s \n",obj->query("equipped")? HIC"☆"NOR:"  ",obj->short());
                        obj = next_inventory(obj);
                        continue;
                }
                if (!mapp(my))
                        my=([obj->query("unit")+obj->short():1]);
                else{
                        amount=my[obj->query("unit")+obj->short()];
                        my[obj->query("unit")+obj->short()]=amount+1;
                }
                obj = next_inventory(obj);
        }
        if (mapp(my)){
                str=keys(my);
                for (i=0;i<sizeof(my);i++)
                arg+=sprintf("  %s%s\n",
my[str[i]]==1?"":CHINESE_D->chinese_number(my[str[i]]),
my[str[i]]==1?str[i][2..]:str[i]);
        }
        printf("%s身上带著下列这些东西(负重 %d%%)：\n%s",
                (ob==me)? "你": ob->name(),
                (int)ob->query_encumbrance() * 100 / (int)ob->query_max_encumbrance(),
                arg);
        return 1;
}
int help (object me)
{
        write(@HELP
指令格式: inventory
 
可列出你目前身上所携带的所有物品。
 
注 : 此指令可以 " i " 代替。
 
HELP
);
        return 1;
}