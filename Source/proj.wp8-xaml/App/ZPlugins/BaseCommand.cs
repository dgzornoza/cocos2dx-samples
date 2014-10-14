using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;

namespace PhoneDirect3DXamlAppInterop.ZPlugins
{
    /// <summary>
    /// Base class for create plugins
    /// </summary>
    public abstract class BaseCommand
    {

        /// <summary>
        /// Default constructor
        /// </summary>
        public BaseCommand()
        {
        }

        /// <summary>callback for success result</summary>
        public PhoneDirect3DXamlAppComponent.CompletedFunc SuccessCallback { get; set; }

        /// <summary>callback for error result</summary>
        public PhoneDirect3DXamlAppComponent.CompletedFunc ErrorCallback { get; set; }

        /// <summary>
        /// Function for dispatch default plugin command result
        /// </summary>
        public void DispatchCommandResult()
        {
            this.DispatchCommandResult(new PluginResult(PluginResult.Status.NO_RESULT));
        }

        /// <summary>
        /// Function for dispatch custom plugin command result
        /// </summary>
        /// <param name="result">Plugin result object</param>
        public void DispatchCommandResult(PluginResult _result)
        {
            // invoke callback
            if (_result.StatusResult == PluginResult.Status.OK || _result.StatusResult == PluginResult.Status.NO_RESULT)
            {
                SuccessCallback.Invoke(_result.ToJSONString());
            }
            else SuccessCallback.Invoke(_result.ToJSONString());
        }
    }
}
