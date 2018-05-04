using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using MySql.Data.MySqlClient;
namespace Cyfrowa_Dystrybucja
{
    class DatabaseConnection
    {
        MySqlConnection query = new MySqlConnection("server=sql.ppatrowicz.pl; user=26819092_database; password=wh&DF_-pC-J8; database=26819092_database;");
        MySqlCommand result;
        MySqlDataReader record;
    }
}
