using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PhoneDirect3DXamlAppInterop
{
    /// <summary>
    /// zplugin native command handler for cocos2dx interop.
    /// this class handle comunication platform native code -> cocos2dx.
    /// </summary>
    public class PlatformCommandHandler : PhoneDirect3DXamlAppComponent.IPlatformCommandHandler
    {
        /// <summary>
        /// default constructor
        /// </summary>
        public PlatformCommandHandler()
        {
            System.Diagnostics.Debug.WriteLine("in c-sharp constructor");
            PhoneDirect3DXamlAppComponent.CommandHandler.setPlatformCommandHandler(this);
        }


        public void exec(String _className, String _funcName, String _params)
        {
            //Execute some C# code, if you call UI stuff you will need to call this too
            /*Deployment.Current.Dispatcher.BeginInvoke(() =>
            {
            });*/

            System.Diagnostics.Debug.WriteLine("C# method---" + _funcName + "-----" + _params);

        }
    }

}
