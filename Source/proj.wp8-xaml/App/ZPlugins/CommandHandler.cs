using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PhoneDirect3DXamlAppInterop
{
    /// <summary>
    /// zplugin command handler for cocos2dx interop.
    /// this class handle comunication between platform native code and cocos2dx.
    /// </summary>
    public class CommandHandler : PhoneDirect3DXamlAppComponent.ICommandHandler
    {
        /// <summary>
        /// default constructor
        /// </summary>
        public CommandHandler()
        {
            System.Diagnostics.Debug.WriteLine("in c-sharp constructor");
            PhoneDirect3DXamlAppComponent.PluginWrapper.SetCallback(this);
        }


        public void Exec(String Command, String Param)
        {
            //Execute some C# code, if you call UI stuff you will need to call this too
            /*Deployment.Current.Dispatcher.BeginInvoke(() =>
            {
            });*/

            System.Diagnostics.Debug.WriteLine("C# method---" + Command + "-----" + Param);

        }
    }

}
