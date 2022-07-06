#include "rs232scriptparser.h"

RS232ScriptParser::RS232ScriptParser()
{

}

int RS232ScriptParser::parse(QString cmd)
{

    if(cmd.startsWith('.'))
    {
        if(cmd.startsWith(".sleep"))
        {
            //thread needs to sleep

        }
    }
    else if(cmd.startsWith('#')){
        return 0;
    }

    return 0;
}
