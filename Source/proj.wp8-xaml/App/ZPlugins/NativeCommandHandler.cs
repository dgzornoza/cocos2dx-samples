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
    public class NativeCommandHandler : PhoneDirect3DXamlAppComponent.ICommandHandler
    {
        /// <summary>
        /// default constructor
        /// </summary>
        public NativeCommandHandler()
        {
            System.Diagnostics.Debug.WriteLine("in c-sharp constructor");
            PhoneDirect3DXamlAppComponent.PlatformCommandHandler.setCommandHandler(this);
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
