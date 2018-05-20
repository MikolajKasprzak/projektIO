using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data;
using System.Data.Sql;
using System.Data.SqlClient;
using System.Data.SqlTypes;

namespace Platforma_Cyfrowej_Dystrybucji
{
    class ServerConnection
    {
        private SqlConnection polaczenie;
        public ServerConnection()
        {
            polaczenie = new SqlConnection();
            // polaczenie.ConnectionString = "server=sql.ppatrowicz.pl; user=26819092_database; password=wh&DF_-pC-J8; database=26819092_database;" ;
            //polaczenie.ConnectionString = "Server = sql.ppatrowicz.pl; Database = 26819092_database; User Id=26819092_database; Password = wh&DF_-pC-J8; ";
          //  polaczenie.ConnectionString = "Server=sql.ppatrowicz.pl;Database=26819092_database;Uid=26819092_database;Pwd=wh&DF_-pC-J8;";
            polaczenie.ConnectionString = "SERVER=sql.ppatrowicz.pl;" + "DATABASE=26819092_database;"+ " UID=26819092_database@localhost;" + "PASSWORD=wh&DF_-pC-J8;";
            polaczenie.Open();
        }
    }
}
