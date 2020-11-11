//С��.c
//����һ��ǰ���ĳ���ϵͳ���ĵ� С����ϵͳ
//by xgchen@fy
#include <ansi.h>
#include <combat.h>
#define PET_MARKING "/d/fy/fqkhotel"
inherit NPC;

static int last_age_set;

void create()
{
        set_name("Ӥ��", ({ "baby" }) );
        set("race", "����");
        set("age",0);
        set("str",10);
        set("cor",10);
        set("int",10);
        set("spi",0);
        set("cps",10);  
        set("per",10);
        set("con",10);
        set("agi",10);
        set("dur",10);
        set("fle",10);
    set("go_free",1);
    set("can_carry",1);
        set("tol",10);
        set("max_kee",300);
        set("max_gin",300);
        set("max_sen",300);
        set("long", "һ��СӤ����\n");
        set("owner","R");
        set("limbs", ({ "ͷ��", "����", "ǰ��", "�ᱳ","˫��" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("obedience",60);
        set("combat_exp",1000);
        set("deathstamp",1);
        setup();
}
string query_save_file()
{
        string id;

        id = query("owner");
        if( !stringp(id) ) return 0;
        return sprintf(DATA_DIR "user/%c/%s/%s", id[0],id, id+".pet");
}

int save()
{
        string file;
        int gin, kee, sen;

        gin = (int) query("max_gin");
        kee = (int) query("max_kee");
        sen = (int) query("max_sen");
        set("eff_kee",kee);
        set("eff_gin",gin);
            set("eff_sen",sen);
        set("kee",kee);
        set("gin",gin);
        set("sen",sen);

        if( stringp(file = this_object()->query_save_file()) ) {
                assure_file(file+ __SAVE_EXTENSION__);
                return save_object(file);
        }
        return 0;
}
int restore()
{
        string file;

        if( stringp(file = this_object()->query_save_file()) )
            return restore_object(file);
        return 0;
}

//ʳ�����������������ӡ�
int max_food_capacity() { return 10+10*query("age"); }
int max_water_capacity() { return 10+10*query("age"); }

void die()
{       
        int i;
        object owner, *enemy;
        int gin,kee,sen,exp;
        exp = (int) query("combat_exp");
        gin = (int) query("max_gin");
        kee = (int) query("max_kee");
        sen = (int) query("max_sen");
        if(!environment()->query("no_death_penalty")){
          set("deathstamp",time());
          set("combat_exp",exp/10 * 9);
        }
        set("eff_kee",kee);
        set("eff_gin",gin);
        set("eff_sen",sen);
        set("kee",kee);
        set("gin",gin);
        set("sen",sen);
        if(objectp(owner=query("possessed")))
        {
                enemy = query_enemy();
        i = sizeof(enemy);
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        owner->kill_ob(enemy[i]);
                }
        }

        }

        save(); 
        ::die();
}

//�᳤��
void update_age()
{

        if( !last_age_set ) last_age_set = time();
        add("mud_age", time() - last_age_set);
        last_age_set = time();
        set("age", (int)query("mud_age") / 172800);
}


int heal_up()
{
        object owner=this_object()->query("possessed");
 //ͬ�������䡣
        update_age();
        if(!objectp(owner))
        {
        save();
        message_vision("$Nȥ��ȥ�ˣ������ˡ�\n",this_object());
        destruct(this_object());
        return 1;
        }
        //���ڲ�ι����ѵ���Ƚ��͡�
        //�Ӹ�����Ǳ���ģ����Խ���Ϊ�������ͼ���������Ҫ��Ϊ�˷�ֹ��Ϣ���ġ�
        if((query("food")<2||query("water")<2)&&!random(5))
        {
        if(environment()==owner->environment()) 
        message_vision("$N��$n��֪���Ƕ��˻��ǿ��ˡ�\n",this_object(),owner);
           add("ask_food",1);
           if(query("ask_food")>5)
    if(random(100)>query("obedience"))
    {
        add("obedience",-1);
         if(environment()==owner->environment())        
         message_vision("$N����Թ���۹⿴�˿�$n��\n",this_object(),owner);
        }
         }
        set_heart_beat(1);
        return ::heal_up() ;
        
  }
void init()
{
        if(this_player() == query("possessed"))
        {
        add_action("do_order","order");
        add_action("do_modify","modify");
        add_action("do_gongji","gongji");
        add_action("do_teach","teach");
        add_action("do_shape","shape");
    add_action("do_weiyang","weiyang");
    add_action("do_mai","mai");
        }

}

//ι����
int do_weiyang(string arg)
  {
object me,ob,food;
if(!arg||arg=="")
return notify_fail("�����ʽ:weiyang <ʳ���ˮ��id>\n");
ob=this_object();
me=ob->query("possessed");
if(me!=this_player())
{
command("yawn "+this_player()->query("id"));
return 1;
  }

if(!(food=present(arg,ob)))
{
if(!(food=present(arg,me)))
return notify_fail("������û��"+arg+"����������\n");
if(!food->is_food()&&!food->is_liquid()||!food->query("babyeat"))
return notify_fail("�ⶫ���Ȳ��ܸ�Ӥ���ã�����Ҫ"+name()+"����ѽ��\n");
if(food->move(ob))
message_vision("$N��$n�ŵ�"+name()+"����ߡ�\n",me,food);
else return notify_fail(name()+"���ڲ���Զ�����\n");
 }
if(food->is_food())
{
if(ob->query("food")>=ob->max_food_capacity())
return notify_fail(name()+"�Ѿ��ԵĹ����ˣ���Ҫ������ѽ��\n");
command("eat "+arg);
message_vision("$N���ĵ�ι$n����һЩ"+food->name()+"��\n",me,ob);
return 1;
}

else if(food->is_liquid())
{
if(ob->query("water")>=ob->max_water_capacity())
return notify_fail(name()+"�Ѿ�����̫�ණ���ˣ���Ҫ������ѽ��\n");
command("drink "+arg);
message_vision("$N���ĵ�ι$n����һ��"+food->query("liquid/name")+"��\n",me,ob);
return 1;
}
else return notify_fail("�ⶫ���Ȳ��ܳ��ֲ��ܺȣ�����Ҫ"+name()+"����ѽ��\n");

 }

int do_order(string arg)
{
       int i;
        int obedience;
       string arg1;
        object me = this_player();
        me->add("sen",-5);
        obedience = query("obedience");
        if(random(100) > obedience )
        {
        command("emote �ܲ���Ը�����ӡ�");
        return 1;
   }            
   if(!arg||arg=="")
   {
   command("emote �ɻ�ؿ���"+me->query("name")+"��\n");
   return 1;    
        }
  //��ֹʹ�õ����
      if( strsrch(arg, "follow") != -1 ||
          strsrch(arg, "apprentice") != -1 ||
          strsrch(arg, "promote") != -1 ||
          strsrch(arg, "recruit") != -1 )
         {   
            command( "emote " + arg);
            return 1;
        }

//������Ƶ����
//��ʱ�޷��ڹ���Ƶ��ʹ��emote.
      if( strsrch(arg, "fy ") != -1 ||
          strsrch(arg, "chat ") != -1 )
         {   
            command(arg);
            return 1;
        }

        i = strlen(arg);
       while(i--) {
                if(is_chinese(arg[i..<0]) ) {
            command( "emote " + arg);
            return 1;
                }
        }                       
        command(arg);
        return 1;
}

int do_modify(string arg)
{
        string item, msg;
        object me = this_player();
        if(!arg || sscanf(arg,"%s %s",item,msg) != 2)
        return notify_fail("�����ʽ: modify ���� ����\n");
        if(item == "flee")
        {
                set("env/wimpy", atoi(msg));
                write("�ϣ�\n");
                save();
                return 1;
        }
                
                if(CHINESE_D->check_control(msg))
                return notify_fail("���������п��Ʒ���\n");
        me->add("sen",-10);
        msg = replace_string(msg, "$BLK$", BLK);
        msg = replace_string(msg, "$RED$", RED);
        msg = replace_string(msg, "$GRN$", GRN);
        msg = replace_string(msg, "$YEL$", YEL);
        msg = replace_string(msg, "$BLU$", BLU);
        msg = replace_string(msg, "$MAG$", MAG);
        msg = replace_string(msg, "$BNK$", BLINK);
        msg = replace_string(msg, "$CYN$", CYN);
        msg = replace_string(msg, "$WHT$", WHT);
        msg = replace_string(msg, "$HIR$", HIR);
        msg = replace_string(msg, "$HIG$", HIG);
        msg = replace_string(msg, "$HIY$", HIY);
        msg = replace_string(msg, "$HIB$", HIB);
        msg = replace_string(msg, "$HIM$", HIM);
        msg = replace_string(msg, "$HIC$", HIC);
        msg = replace_string(msg, "$HIW$", HIW);
        msg = replace_string(msg, "$NOR$", NOR);
        msg += NOR;
        switch(item)
        {
        case "desc":
                if(CHINESE_D->check_length(msg) > 150)
                return notify_fail("����̫����\n"); 
                set("long",msg+"\n");
                write("�ϣ�\n");
                save();
                return 1;
        case "nickname" :
                if(CHINESE_D->check_length(msg) > 60)
                return notify_fail("����̫����\n");
                set("nickname",msg);
                write("�ϣ�\n");
                save();
                return 1;
        case "name" :
                if(CHINESE_D->check_length(msg) > 30)
                return notify_fail("����̫����\n");
                set("name",msg);
                write("�ϣ�\n");
                save();
                return 1;

        case "title" :
                if(CHINESE_D->check_length(msg) > 40)
                return notify_fail("����̫����\n");
                set("title",msg);
                write("�ϣ�\n");
                save();
                return 1;
        case "arrive_msg" :
                if(CHINESE_D->check_length(msg) > 40)
                return notify_fail("����̫����\n");
                set("arrive_msg",msg);
                write("�ϣ�\n");
                save();
                return 1;
        case "leave_msg" :
                if(CHINESE_D->check_length(msg) > 40)
                return notify_fail("����̫����\n");
                set("leave_msg",msg);
                write("�ϣ�\n");
                save();
                return 1;

        }
        return notify_fail("��Ҫ�޸�ʲô��\n");

}
int do_gongji(string arg)
{
        object me,obj;
        me = this_player();
        if( environment(me)->query("no_fight") )
                return notify_fail("���ﲻ׼ս����\n");

        if( !arg )
                return notify_fail("����ɱ˭��\n");

        if(!objectp(obj = present(arg, environment(me))))
                return notify_fail("����û������ˡ�\n");

        if( !obj->is_character() || obj->is_corpse() )
                return notify_fail("�����һ�㣬�ǲ����ǻ��\n");
        message_vision(
        sprintf("$N��$nһָ����%s����������ϣ���\n",this_object()->name()),me,obj);
    me->add("sen",-5);
        add("sen",-10);
       if(random(100) > query("obedience") )
        command("emote �ܲ���Ը�غ���һ����");
        else
        kill_ob(obj);
        return 1;
        
}

int do_teach(string arg)
{
        object me;
        int gin_cost,amount;
        int myskill, itskill;
        me = this_player();
        if(!myskill = me->query_skill(arg,1))
        return notify_fail("���������󻹲����أ�\n");
//��ѧ�ļ��ܡ�
        if( arg != "unarmed" && arg != "move" && arg != "dodge"&& arg != "changquan"
     && arg != "parry" && arg != "iron-cloth" && arg != "leadership"
     && arg != "dormancy" && arg != "incarnation" && arg != "literate"
     && arg != "chanting"    )
        return notify_fail("��ѧ��������ܵģ�\n");
        itskill = query_skill(arg,1);
        if(myskill <= itskill)
        return notify_fail(name()+"�Գ�Ц��Ŀ�������㡣\n");
        if((int)me->query("potential")-(int)me->query("learned_points") < 1)
        return notify_fail("���Ǳ�ܲ�����\n");
        gin_cost = 3;
        if((int)me->query("gin") < gin_cost)
        return notify_fail("����Ȼ̫����û�а취�̣�\n");
        me->receive_damage("gin",gin_cost);
        amount = (int)me->query_int() * (int)query_int()*3/100;
        message_vision(sprintf("$N�����䷳�ؽ�$n��%s����\n",to_chinese(arg)),me,this_object());
        me->add("potential",-1);
       if(random(100) > query("obedience") )
        command("emote �ܲ���Ը�غ���һ����");
        else {
        improve_skill(arg,amount);
        message_vision(sprintf("$N�ƺ����ѧ����һЩ��%s����\n",to_chinese(arg)),this_object());
    }
    return 1;

}

string status_color(int current, int max)
{
        int percent;

        if( max>0 ) percent = current * 100 / max;
        else percent = 100;
        if( percent > 100 ) return HIC;
        if( percent >= 90 ) return HIG;
        if( percent >= 60 ) return HIY;
        if( percent >= 30 ) return YEL;
        if( percent >= 10 ) return HIR;
        return RED;
}
//��ʾ״̬��
int do_shape(string arg)
{       mapping my;
        string shape;
        int at_pt,pa_pt,do_pt;
        my = query_entire_dbase();
        printf("����%s%3d/ %3d %s(%3d%%)"NOR"  ����%s%3d/ %3d %s(%3d%%)"NOR"  ��%s%3d/ %3d %s(%3d%%)\n"+NOR,
                status_color(my["gin"], my["eff_gin"]), my["gin"],my["eff_gin"],
                status_color(my["eff_gin"], my["max_gin"]),     my["eff_gin"] * 100 / my["max_gin"],
                status_color(my["kee"], my["eff_kee"]), my["kee"], my["eff_kee"],
                status_color(my["eff_kee"], my["max_kee"]),     my["eff_kee"] * 100 / my["max_kee"],
                status_color(my["sen"], my["eff_sen"]), my["sen"], my["eff_sen"],
                status_color(my["eff_sen"], my["max_sen"]),     my["eff_sen"] * 100 / my["max_sen"]
        );              
        printf("���ˣ� %s\t\t���飺 %d\t\tɱ���� %d\n",
        my["owner"], my["combat_exp"],my["bellicosity"]
        );
        printf("���ǣ� %d\t\t���ʣ� %d\t\t��̬�� %d\n",
        query_int(), query_con(),query_per()
        );
        printf("���ԣ� %d\t\t������ %d\t\t������ %d\n",
        query_cor(), query_str(),query_fle()
        );
        printf("�ٶȣ� %d\t\t���ԣ� %d\t\t���ԣ� %d\n",
        query_agi(), query_tol(),query_dur()
        );
        printf("ʳ� %d\t\t��ˮ�� %d\t\t���䣺 %d\n",
        my["food"], my["water"],my["age"]
        );
        at_pt= COMBAT_D->skill_power(this_object(), "unarmed", SKILL_USAGE_ATTACK);
        pa_pt= COMBAT_D->skill_power(this_object(), "unarmed", SKILL_USAGE_DEFENSE);
        do_pt= COMBAT_D->skill_power(this_object(), "dodge", SKILL_USAGE_DEFENSE);
        printf("�������� %d\t\t\t\t�������� %d\n\n",
        at_pt+1, pa_pt/2+do_pt/2+1
        );
        printf("/cmds/usr/skills"->pet_skill(this_object()));
        return 1;
}
void unconcious()
{
 save();
}

//added by lion@hero
//to make fun,let pet can buy sth for it's owner
int accept_object(object who, object ob)
{
 if(who==this_object()->query("possessed"))
return 1;
}

int do_mai(string arg)
{
   int i,value,flag;
   object *inv;
   object ob,me;
   value=0;
   ob = this_object();
   me=ob->query("possessed");
   if(!me||!userp(me))
   return notify_fail(name()+"�Բ�м���۹⿴�˿��㡣\n");
   if(!arg||arg=="")
   return notify_fail("�����ʽ:mai <��Ʒid>���������Ʒֻ�����ڷ���˿�ջ���۵���Ʒ��\n");
   inv=all_inventory(ob);
   for(i=0;i<sizeof(inv);i++)
  {
    if(inv[i]->is_money())
    value +=inv[i]->value();
   }
   if(!value)
   return notify_fail(name()+"����һ��Ǯ��û���أ��㲻����Ϊ����\n");
   if(value<100)
   return notify_fail(name()+"�������ε������ʼ磬�ƺ���˵���ɸ���Ϊ����֮��ѽ��\n");
   message_vision("$N�ƺ�������$n��ʲô���һת�۾Ͳ����ˡ�\n",ob,me);
//�������̵ꡣ
   ob->move(PET_MARKING);
   call_out("buy_for_owner",10+random(20),arg);
   return 1;
 }

void buy_for_owner(string arg)
{
object ob,owner,obj;
command("buy "+arg+" from waiter");
ob = this_object();     
obj = present(arg,ob);
if(!obj)
message_vision("$N�������������ʲô�����ƺ�û�򵽡�\n",ob);
else 
message_vision("$N�ӵ�С����������һ��$n,Ȼ��һת�۾Ͳ����ˡ�\n",ob,obj);
owner = ob->query("possessed");
if(!objectp(owner))
  {
        save();
    destruct(this_object());    
        }
if(!objectp(environment(owner)))
  {
        save();
    destruct(this_object());    
        }
if(!(ob->move(environment(owner))))
   {
        tell_object(owner,name()+"��·�ˣ����ȥ����˿�ջ���������ɡ�\n");
        return;
    }
obj = present(arg,ob);
if(!obj)
 {
command("sorry "+owner->query("id"));
tell_object(owner,name()+"�ƺ�û������㽻����������\n");
return;
 }
command("give "+arg+" to "+owner->query("id"));
message_vision("$N����һ��"+obj->name()+"����$n��$n�е�ʮ�ָ��ˡ�\n",ob,owner);
return;

}