// more.c

#include <ansi.h>
#include <dbase.h>

#define LINES_PER_PAGE          24

void more(string cmd, string *text, int line)
{
        int i, j;
        string show;

        show = ESC + "[256D" + ESC + "[K";
        show = ESC + "[1A" + ESC "[256D" + ESC + "[K";

        switch (cmd)
        {
        default:
                i = line + LINES_PER_PAGE;
                if (i >= sizeof(text)) i = sizeof(text) - 1;
                show += implode(text[line..i], "\n") + "\n";
                if (i == sizeof(text) - 1)
                {
                        write(show);
                        return;
                }
                line = i + 1;
                break;

        case "b":
                line -= LINES_PER_PAGE * 2;
                if (line <= 0)
                {
                        line = 0;
                        show += WHT "-------- �ļ��Ķ��� --------\n" NOR;
                }

                i = line + LINES_PER_PAGE;
                if (i >= sizeof(text)) i = sizeof(text) - 1;
                show += implode(text[line..i], "\n") + "\n";
                line = i + 1;
                break;

        case "q":
                write(show);
                return;
        }
        show += sprintf(NOR WHT "== δ����� " HIY "%d%%" NOR
                        WHT " == (ENTER ������һҳ��q �뿪��b ǰһҳ)" NOR,
                        line * 100 / sizeof(text));
        write(show);
        input_to("more", text, line);
}

#define MAX_STRING_SIZE                 8000

void start_more(string msg)
{
        int len;
        int n;
        int nd;

        if (! stringp(msg) || (len = strlen(msg)) < 1)
                // û������
               return;

        if (query("env/no_more"))
        {
                if (len > MAX_STRING_SIZE)
                {
                        // the string too long ?
                        n = 0;
                        while (n < len)
                        {
                                // show section of the string
                                nd = n + MAX_STRING_SIZE;
                                if (nd >= len) nd = len - 1;
                                write(msg[n..nd]);
                                n = nd + 1;
                        }
                        write("\n");
                } else
                {
                        write(msg);
                        if (msg[strlen(msg) - 1] != '\n') write("\n");
                }
                return;
        }

        more("", explode(msg, "\n"), 0);
}
