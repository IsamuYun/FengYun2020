//xgchen@zzfy
// message.c
#include <ansi.h>

varargs void message_vision(string msg, object me, object you)
{
        string my_gender, your_gender, my_name, your_name;
        string str1, str2, str3;
        object *ob;
        int n,t,i;

        my_name= me->name();
        my_gender = me->query("gender");
        str1 = replace_string(msg,  "$P", gender_self(my_gender));
        str1 = replace_string(str1, "$N", gender_self(my_gender));
        str3 = replace_string(msg,  "$P", my_name);
        str3 = replace_string(str3, "$N", my_name);
        if( you ) {
                your_name= you->name();
                your_gender= you->query("gender");
                str2 = replace_string(msg,  "$P", gender_pronoun(my_gender));
                str2 = replace_string(str2, "$p", gender_self(your_gender));
                str2 = replace_string(str2, "$N", my_name);
                str2 = replace_string(str2, "$n", gender_self(your_gender));
                message("vision", str2, you);
                str1 = replace_string(str1, "$p", gender_pronoun(your_gender));
                str1 = replace_string(str1, "$n", your_name);
                str3 = replace_string(str3, "$p", your_name);
                str3 = replace_string(str3, "$n", your_name);
        }
        message("vision", str1, me);
        if(environment(me))
        message("vision", str3,  environment(me), ({ me, you}) );

        if( environment(me) ) 
                if( n = environment(me)->query("fight_room") ) {
                        ob = users();
                        i = sizeof(ob);
                        while( i-- ) {
                                if( !ob[i]) continue;
                                if( !environment( ob[i] ) )continue;
                                if( environment( ob[i] )->query("watch_fight_room") == n ) {
                                        message("vision", HIY "�����ֳ�: " NOR + str3,  environment( ob[i] ), ({ me, you }) );
                                        break;
                                }
                        }
        }
                if( environment(me) ) 
                if( n = environment(me)->query("fight_room2") ) {
                        ob = users();
                        i = sizeof(ob);
                        while( i-- ) {
                                if( !ob[i]) continue;
                                if( !environment( ob[i] ) )continue;
                                if( environment( ob[i] )->query("watch_fight_room2") == n ) {
                                        message("vision", HIM "Ů���ֳ�: " NOR + str3,  environment( ob[i] ), ({ me, you }) );
                                        break;
                                }
                        }
        }
if( environment(me) ) 
                if( n = environment(me)->query("jianyu_room") ) {
                        ob = users();
                        i = sizeof(ob);
                        while( i-- ) {
                                if( !ob[i]) continue;
                                if( !environment( ob[i] ) )continue;
                                if( environment( ob[i] )->query("watch_jianyu_room") == n ) {
                                        message("vision", HIR "������: " NOR + str3,  environment( ob[i] ), ({ me, you }) );
                                        break;
                                }
                        }
        }
}

void tell_object(object ob, string str)
{
        message("tell_object", str, ob);
}

varargs void tell_room(mixed ob, string str, object *exclude)
{
        if( ob ) message("tell_room", str, ob, exclude);
}

void shout(string str)
{
        message("shout", str, users(), this_player());
}

void write(string str)
{
        if( this_player() )
                message("write", str, this_player());
        else if( previous_object() )
                message("write", str, previous_object());
        else
                efun::write(str);
}

varargs void say(string str, mixed exclude)
{
        if( living(previous_object()) )
                message("say", str, environment(previous_object()), previous_object());
        else if( this_player() )
                message("say", str, environment(this_player()), this_player());
}

