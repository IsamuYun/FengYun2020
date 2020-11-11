inherit F_CLEAN_UP;

string *gifts=({ "gin","kee","sen" });
string *gifts1=({"atman","force","mana"});

int main(object me, string str)
{
    int i;
    object obj;

    if( !str || str == "")
        obj = me;
    else if ( !obj = present(str,environment(me)))
        return notify_fail("�������: �Ҳ���"+str+"\n");
    
    for( i = 0; i < sizeof(gifts); i++ )
    {
        obj->set(gifts[i],obj->query("max_"+gifts[i]));
        obj->set("eff_"+gifts[i],obj->query("max_"+gifts[i]));
    }
    for( i = 0; i < sizeof(gifts1); i++ )
    {
        obj->set(gifts1[i],obj->query("max_"+gifts1[i]));
    }
    obj->set("food",obj->max_food_capacity());
    obj->set("water",obj->max_water_capacity());
    obj->clear_condition();
    write("�ָ��ɹ���\n");
    return 1;
}

int help(object obj)
{
  write(@HELP
ָ���ʽ : full <����>

���ô�ָ�����ȫ�ָ������״̬�����һ��condition��
HELP
    );
    return 1;
}
