using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using com.dgzornoza.cordova.plugins.Models;
using PhoneDirect3DXamlAppInterop.ZPlugins;

namespace com.dgzornoza.cordova.plugins
{
    /// <summary>
    /// Clase para implementar un plugin para la gestion de archivos multimedia mediante phonegap/cordova
    /// </summary>
    public class ZMedia : BaseCommand
    {

        #region [Variables miembro]

        /// <summary>
        /// Enumeracion con los diferentes errores del plugin
        /// </summary>
        public enum enumErrors
        {
            /// <summary>Error ocurrido al seleccionar una imagen</summary>
            ERROR_CHOOSE_IMAGE = -1
        }

        #endregion [Variables miembro]


        #region [Inicializacion]

        /// <summary>
        /// Constructor por defecto de la clase
        /// </summary>
        public ZMedia()
        {
        }

        #endregion [Inicializacion]


        #region [Propiedades]

        #endregion [Propiedades]


        #region [Funciones publicas]

        /// <summary>
        /// Funcion para obtener los items de un albun especificado mediante lso parametros de entrada
        /// </summary>
        /// <param name="_params">
        /// cadena con los parametros en JSON pasados desde javascript, la funcion acepta un objeto de tipo <see cref="AlbumFilterModel"/> serializado en json como primer parametro.
        /// </param>
        /// <remarks>
        /// Los albunes seran retornados en un array de objetos del tipo <see cref="AlbumItemModel"/> serializado en JSON.
        /// </remarks>
        public void GetAlbumItems(string _params)
        {
            PluginResult result = null;

            try
            {
                var json = JsonHelper.Deserialize<string[]>(_params);

                // deserializar parametros de entrada (se selecciona solo el primero)
                AlbumFilterModel filter = JsonHelper.Deserialize<AlbumFilterModel>(json[0]);

                // obtener albums del tipo especificado por los parametros de entrada
                switch (filter.AlbumType)
                {
                    // Imagenes
                    case enumAlbumTypes.PICTURES:

                        // obtener todas las imagenes para el filtro especificado
                        AlbumItemModel[] items = AlbumItems.GetPictureAlbumItems(filter.Path);
                        // retornar el resultado en base 64
                        result = new PluginResult(PluginResult.Status.OK, items);
                        break;

                    default:
                        result = new PluginResult(PluginResult.Status.OK, null);
                        break;
                }
            }
            catch (Exception ex)
            {
                // retornar el resultado con el error
                result = new PluginResult(PluginResult.Status.ERROR, enumErrors.ERROR_CHOOSE_IMAGE.ToString());
                System.Diagnostics.Debug.WriteLine("Plugin ZMedia - GetPhotoAlbums ERROR: " + ex.Message);
            }

            // retornar el resultado de la accion
            DispatchCommandResult(result);
        }

        /// <summary>
        /// Funcion para abrir el dialogo de seleccion de imagen nativo para seleccionar una imagen
        /// </summary>
        /// <param name="_params">cadena con los parametros en JSON pasados desde javascript (Esta funcion no necesita ninguno)</param>
        public async void ChooseImage(string _params)
        {
            try
            {
                // seleccionar imagen asincronamente
                //byte[] image = await AlbumItems.ChooseImage();

                // retornar el resultado con la imagen en base 64
                //DispatchCommandResult(new PluginResult(PluginResult.Status.OK, Convert.ToBase64String(image)));
            }
            catch (Exception ex)
            {
                // retornar el resultado con el error
                DispatchCommandResult(new PluginResult(PluginResult.Status.ERROR, enumErrors.ERROR_CHOOSE_IMAGE.ToString()));
                System.Diagnostics.Debug.WriteLine("Plugin ZMedia - ChooseImage ERROR: " + ex.Message);
            }
        }

        /// <summary>
        /// Metodo de prueba
        /// </summary>
        /// <param name="_params">cadena con los parametros en JSON pasados desde javascript</param>
        public void test(string _params)
        {
            // deserializar parametros de entrada
            var json = JsonHelper.Deserialize<string[]>(_params);


            // retornar sin valor de retorno
            //DispatchCommandResult();

            // retornar con con resultado en JSON
            DispatchCommandResult(new PluginResult(PluginResult.Status.OK, "{result:\"prueba de resultado!\"}"));

        }

        #endregion [Funciones publicas]


        #region [Funciones privadas]

        #endregion [Funciones privadas]

    }
}
