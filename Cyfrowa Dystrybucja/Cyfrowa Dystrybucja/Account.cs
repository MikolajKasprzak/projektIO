using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Cyfrowa_Dystrybucja
{
    public abstract class Account
    {
        public string nick, mail, password;
        Wallet wallet;
        List<Product> productList;
        public abstract void ShowProductsList();
    }
}
