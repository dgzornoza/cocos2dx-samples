using Microsoft.Phone.Tasks;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace com.dgzornoza.cordova.plugins
{
    /// <summary>
    /// Clase con funciones de ayuda
    /// </summary>
    public static class Helpers
    {
        /// <summary>
        /// Metodo extensor para mostrar un dialogo 'chooser' de seleccion de forma asincrona mediante asyn/await
        /// </summary>
        /// <typeparam name="TTaskEventArgs">Tipo de los argumentos del evento del chooser</typeparam>
        /// <param name="_chooser">Referencia al chooser a usar para mostrar asincronamente</param>
        /// <returns>tarea con el resultado del chooser espeficicado en los parametros de entrada</returns>
        public static Task<TTaskEventArgs> ShowChooserAsync<TTaskEventArgs>(this ChooserBase<TTaskEventArgs> _chooser) where TTaskEventArgs : TaskEventArgs
        {
            // crear tarea para ejecucion asincrona y envento ocurrido al completarse la tarea en el chooser
            TaskCompletionSource<TTaskEventArgs> taskCompletionSource = new TaskCompletionSource<TTaskEventArgs>();
            EventHandler<TTaskEventArgs> completed = null;

            // definir el evento de tarea completada
            completed = (s, e) =>
            {
                // eliminar el evento
                _chooser.Completed -= completed;
                // establecer el resultado en la tarea
                taskCompletionSource.SetResult(e);
            };

            // crear evento de tarea completada y mostrar el chooser
            _chooser.Completed += completed;            
            _chooser.Show();

            // retornar la tarea
            return taskCompletionSource.Task;
        }

        /// <summary>
        /// Metodo extensor para convertir un stream en una cadena en base64
        /// </summary>
        /// <param name="_stream">Stream a convertir</param>
        /// <returns>cadena en base 64 con el stream</returns>
        public static string ConvertToBase64(this System.IO.Stream _stream)
        {
            // convertir el stream a base64
            byte[] bytes = _stream.GetBytes();
            string result = Convert.ToBase64String(bytes);

            return result;
        }

        /// <summary>
        /// Metodo extensor para convertir un stream en una cadena en base64
        /// </summary>
        /// <param name="_stream">Stream a convertir</param>
        /// <returns>cadena en base 64 con el stream</returns>
        public static byte[]  GetBytes(this System.IO.Stream _stream)
        {
            byte[] bytes = new byte[_stream.Length];
            _stream.Read(bytes, 0, bytes.Length);

            return bytes;
        }
    }
}
