using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.Serialization.Json;
using System.Text;
using System.Threading.Tasks;

namespace PhoneDirect3DXamlAppInterop.ZPlugins
{
    /// <summary>
    /// Provides JSON serialization/deserialization functionality.
    /// </summary>
    public static class JsonHelper
    {
        /// <summary>
        /// Serializes object to JSON UTF-8 string representation
        /// </summary>
        /// <param name="_objectToSerialize">object to serialize</param>
        /// <returns>JSON representation of the object. Returns 'null' string for null passed as argument</returns>
        public static string Serialize(object _objectToSerialize)
        {
            // result
            string jsonResult = null;

            // verify input param
            if (_objectToSerialize == null) return jsonResult;

            // serialize object in json UTF-8
            using (System.IO.MemoryStream stream = new System.IO.MemoryStream())
            {
                // create serializer
                DataContractJsonSerializer jsonSerializer = new DataContractJsonSerializer(_objectToSerialize.GetType());
                // write in stream
                jsonSerializer.WriteObject(stream, _objectToSerialize);
                // get string from stream in UTF-8
                jsonResult = System.Text.Encoding.UTF8.GetString(stream.ToArray(), 0, (int)stream.Length);
            }


            return jsonResult;

        }


        /// <summary>
        /// Parses json utf-8 string to object instance
        /// </summary>
        /// <typeparam name="T">type of the object</typeparam>
        /// <param name="_json">json string representation of the object</param>
        /// <returns>Deserialized object instance, null if can not deserialize.</returns>
        public static T Deserialize<T>(string _json)
        {
            DataContractJsonSerializer deserializer = new DataContractJsonSerializer(typeof(T));
            object result = null;
            try
            {
                using (MemoryStream mem = new MemoryStream(Encoding.UTF8.GetBytes(_json)))
                {
                    result = deserializer.ReadObject(mem);
                }
            }
            catch (Exception ex)
            {
                System.Diagnostics.Debug.WriteLine(ex.Message);
                System.Diagnostics.Debug.WriteLine("Failed to deserialize " + typeof(T) + " with JSON value :: " + _json);
            }

            return (T)result;

            //// invoke overload function
            //T result = (T)Deserialize(typeof(T), _json);

            //// return object
            //return result;
        }

        /// <summary>
        /// Parses json utf-8 string to object instance
        /// </summary>
        /// <param name="_objectType">object type to deserialize</param>
        /// <param name="_json">json string representation of the object</param>
        /// <returns>Deserialized object instance, null if can not deserialize.</returns>
        public static object Deserialize(Type _objectType, string _json)
        {
            // return object
            object result = null;

            // verify input params
            if (null == _objectType || string.IsNullOrWhiteSpace(_json)) return result;

            try
            {
                // create stream and deserialize object
                using (System.IO.MemoryStream stream = new System.IO.MemoryStream(Encoding.UTF8.GetBytes(_json)))
                {
                    DataContractJsonSerializer jsonDeserializer = new DataContractJsonSerializer(_objectType);
                    result = jsonDeserializer.ReadObject(stream);
                }
            }
            catch (Exception ex)
            {
                System.Diagnostics.Debug.WriteLine(ex.Message);
                System.Diagnostics.Debug.WriteLine("Failed to deserialize " + _objectType + " with JSON value :: " + _json);
            }

            // return object
            return result;
        }

    }
}
