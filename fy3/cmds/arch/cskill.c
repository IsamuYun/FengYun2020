/* ��������ԡ��ռ���������һ����ʦ������԰Ѷ���������书��״̬���ơ���û��CALL����ĵ׵ȼ���ʦ�кܴ��ô���*/ 
//������xgchen@zzfy
#include <ansi.h>//�̳���ɫ

inherit F_CLEAN_UP;

private int copy_skill(object me, object ob);//����һ��˽�к���
int help();//����HELP����

int main(object me, string arg)
{
object ob;

if (! arg)//û�в���ʱ�͵���HELP����
{
help();
return 1;
}

if (! objectp(ob = present(arg, environment(me))))//�ж϶����Ƿ�������
return notify_fail("����ǰû������ˡ�\n");

if (! wizardp(me))//�ж��Ƿ�����ʦ
return notify_fail("ֻ����ʦ�ſ��Ը��Ʊ��˵��书��\n");

copy_skill(me, ob);//��ʼ���ú���COPY�书��״̬
message_vision(HIM "$N���������дʣ�ֻ��һ�����������$N��$n��\n" NOR,
me, ob);//��ʾ��״̬
return 1;
}

private int copy_skill(object me, object ob)
{
mapping hp_status, skill_status, map_status, prepare_status;
mapping my;
string *sname, *mname, *pname;
int i, temp;

if (mapp(skill_status = me->query_skills()))//�ж��Լ��Ƿ��й������н����������ȫ��ɾ��
{
skill_status = me->query_skills();
sname = keys(skill_status);//���������Լ��Ĺ�������

temp = sizeof(skill_status);
for (i = 0; i < temp; i++)
me->delete_skill(sname[i]);//ɾ���Լ����й���
}

if (mapp(skill_status = ob->query_skills()))//�ж϶����Ƿ��й������н��������������ȫ������
{
skill_status = ob->query_skills();
sname = keys(skill_status);//�������ж��󹦷�����

for (i = 0; i < sizeof(skill_status); i++)
me->set_skill(sname[i], skill_status[sname[i]]);//Ϊ�Լ��������й���
}

if (mapp(map_status = me->query_skill_map()))//�ж��Լ��Ƿ�����װ��Ļ�������
{
mname = keys(map_status);

temp = sizeof(map_status);
for (i = 0; i < temp; i++)
me->map_skill(mname[i]);
}

if (mapp(map_status = ob->query_skill_map()))//�ж϶�����װ��Ļ����������н��������������
{
mname = keys(map_status);

for(i = 0; i < sizeof(map_status); i++)
me->map_skill(mname[i], map_status[mname[i]]);
}

if (mapp(prepare_status = me->query_skill_prepare()))//�ж��Լ��Ƿ�����װ������⹦��
{
pname = keys(prepare_status);

temp = sizeof(prepare_status);
for(i = 0; i < temp; i++)
me->prepare_skill(pname[i]);
}

if (mapp(prepare_status = ob->query_skill_prepare()))//�ж϶�����װ������⹦�����н��������������
{
pname = keys(prepare_status);

for(i = 0; i < sizeof(prepare_status); i++)
me->prepare_skill(pname[i], prepare_status[pname[i]]);
}

hp_status = ob->query_entire_dbase();//�õ���������״̬
my = me->query_entire_dbase();//�õ��Լ�����״̬

my["str"] = hp_status["str"];//��ʼ����״̬
my["int"] = hp_status["int"];
my["con"] = hp_status["con"];
my["dur"] = hp_status["dur"];
my["fle"] = hp_status["fle"];
my["cps"] = hp_status["cps"];
my["spi"] = hp_status["spi"];
my["per"] = hp_status["per"];
my["score"] = hp_status["score"];
my["max_kee"] = hp_status["max_kee"];
my["eff_kee"] = hp_status["eff_kee"];
my["kee"] = hp_status["kee"];
my["max_sen"] = hp_status["max_sen"];
my["eff_sen"] = hp_status["eff_sen"];
my["sen"] = hp_status["sen"];
my["max_gin"] = hp_status["max_kee"];
my["eff_gin"] = hp_status["eff_kee"];
my["gin"] = hp_status["gin"];
my["max_force"] = hp_status["max_force"];
my["force"] = hp_status["force"];
my["atman"] = hp_status["atman"];
my["max_mana"] = hp_status["max_mana"];
my["max_atman"] = hp_status["max_atman"];
my["mana"] = hp_status["mana"];
my["combat_exp"] = hp_status["combat_exp"];//��������״̬

me->reset_action();//��������
return 1;
}

int help()//��������
{
write( @TEXT
ָ���ʽ��cskill ����

���ָ�����㸴�ƶ����ս����������е��书���ܡ�
TEXT
);
return 1 ;
}


