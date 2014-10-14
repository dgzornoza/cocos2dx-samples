using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PhoneDirect3DXamlAppInterop.ZPlugins
{
    /// <summary>
    /// Class for declare plugin result
    /// </summary>
    public class PluginResult
    {
        /// <summary>
        /// Predefined resultant messages
        /// </summary>
        public static string[] StatusMessages = new string[] 
		{
			"No result",
			"OK",
			"Class not found",
			"Illegal access",
			"Instantiation error",
			"Malformed url",
			"IO error",
			"Invalid action",
			"JSON error",
			"Error"
		};

        /// <summary>
        /// Possible command results status codes
        /// </summary>
        public enum Status : int
        {
            NO_RESULT = 0,
            OK,
            CLASS_NOT_FOUND_EXCEPTION,
            ILLEGAL_ACCESS_EXCEPTION,
            INSTANTIATION_EXCEPTION,
            MALFORMED_URL_EXCEPTION,
            IO_EXCEPTION,
            INVALID_ACTION,
            JSON_EXCEPTION,
            ERROR
        };

        #region [Initialization]

        /// <summary>
        /// class constructor 
        /// </summary>
        /// <param name="status">plugin result status code</param>
        public PluginResult(Status _status) : this(_status, PluginResult.StatusMessages[(int)_status])
        {
        }

        /// <summary>
        /// class constructor 
        /// </summary>
        /// <param name="_status">plugin result status code</param>
        /// <param name="_objectResult">plugin object result</param>
        public PluginResult(Status _status, object _objectResult)
        {
            this.StatusResult = _status;
            this.ObjectResult = JsonHelper.Serialize(_objectResult);
        }

        #endregion [Initialization]


        #region [Properties]

        /// <summary>
        /// Property for get plugin result status code
        /// </summary>
        public Status StatusResult { get; private set; }
        /// <summary>
        /// Property for get plugin object result
        /// </summary>
        public string ObjectResult { get; set; }

        #endregion [Properties]

        /// <summary>
        /// Function for obtain this object custom result in JSON representation
        /// </summary>
        /// <returns>this object custom result in JSON representation</returns>
        public string ToJSONString()
        {
            // create json custom result  
            string result = String.Format("{{\"status\":{0},\"message\":{1}}}",
                (int)this.StatusResult,
                this.ObjectResult);

            return result;

        }
        /// <summary>
        /// Override for obtain JSON string from this object custom result
        /// </summary>
        /// <returns>this object custom result in JSON representation</returns>
        public override String ToString()
        {
            return this.ToJSONString();
        }

    }

}
