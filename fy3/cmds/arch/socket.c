// socket.c

inherit F_CLEAN_UP;

int help();

int main(object me, string arg)
{
        write(dump_socket_status());
        return 1;
}

int help()
{
        write("����������ָ����ʾ��ǰ socket ����Ự�����\n");
        return 1;
}

