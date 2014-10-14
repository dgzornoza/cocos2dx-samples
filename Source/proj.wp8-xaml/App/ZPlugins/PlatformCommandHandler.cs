using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;

namespace PhoneDirect3DXamlAppInterop.ZPlugins
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

        /// <summary>
        /// Function for call plugin command
        /// </summary>
        /// <param name="_successCallback">callback for success result</param>
        /// <param name="_errorCallback">callback for error result</param>
        /// <param name="_className">Class name in platform code with the function to execute</param>
        /// <param name="_funcName">Function name in the class to execute</param>
        /// <param name="_params">parameters to invoke the function, for complex objects can use json string</param>
        public void exec(PhoneDirect3DXamlAppComponent.CompletedFunc _successCallback, PhoneDirect3DXamlAppComponent.CompletedFunc _errorCallback, string _className, string _funcName, string _params)
        {
            try
            {
                // get type and method
                Type type = Assembly.GetExecutingAssembly().GetType(_className);
                if (null == type) return;
                MethodInfo methodInfo = type.GetMethod(_funcName);

                // create instance
                BaseCommand zplugin = Activator.CreateInstance(type) as BaseCommand;

                // set callbacks 
                zplugin.SuccessCallback = _successCallback;
                zplugin.ErrorCallback = _errorCallback;

                // if exists method, invoke and return
                if (null != methodInfo)
                {
                    // always create json array (compatibility with phonegap/cordova)
                    if (!_params.StartsWith("[")) _params = string.Format("[{0}]", _params);
                    // invoke method
                    methodInfo.Invoke(zplugin, new object[] { _params });
                    return;
                }

                // if not exists method verify if exists property
                if (_params == null)
                {
                    PropertyInfo popertyInfo = this.GetType().GetProperty(_funcName);
                    if (popertyInfo != null)
                    {
                        // invoke property
                        object propertyResult = popertyInfo.GetValue(zplugin, null);

                        // dispatch command result
                        zplugin.DispatchCommandResult(new PluginResult(PluginResult.Status.OK, propertyResult));

                        return;
                    }
                }

                // if not exists method or property show error message
                string error = "C# method---" + _funcName + "------" + _params;
                System.Diagnostics.Debug.WriteLine(error);
                
            }
            catch (Exception ex)
            {
                // show error message
                System.Diagnostics.Debug.WriteLine(ex.Message);
            }

        }
    }

}
