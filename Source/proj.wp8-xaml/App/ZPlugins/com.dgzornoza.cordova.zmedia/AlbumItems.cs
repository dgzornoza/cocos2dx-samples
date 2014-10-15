using com.dgzornoza.cordova.plugins.Models;
using Microsoft.Phone.Tasks;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;



namespace com.dgzornoza.cordova.plugins
{
    /// <summary>
    /// Clase para gestionar items de los albunes de las bibliotecas multimedia del dispositivo
    /// </summary>
    public partial class AlbumItems
    {

        #region [Variables miembro]

        #endregion [Variables miembro]


        #region [Inicializacion]

        /// <summary>
        /// Constructor por defecto de la clase
        /// </summary>
        public AlbumItems()
        {
        }

        #endregion [Inicializacion]


        #region [Propiedades]

        #endregion [Propiedades]


        #region [Funciones publicas]

        /// <summary>
        /// Funcion para obtener todos los items del albun de imagenes de la biblioteca multimedia para la ruta especificada como parametro
        /// </summary>
        /// <param name="_path">Ruta del albun relativa al albun raiz '/'</param>
        /// <returns>Enumeracion de items del albun de imagenes, null en caso de no poder obtenerse</returns>
        public static AlbumItemModel[] GetPictureAlbumItems(string _path)
        {
            AlbumItemModel[] result = null;

            // verificar parametros de entrada
            if (string.IsNullOrWhiteSpace(_path)) return result;

            // contexto para usar la libreria de acceso a imagenes
            using (Microsoft.Xna.Framework.Media.PictureAlbum album = _findPictureAlbum(_path))
            {
                if (null == album) return null;

                // crear los items de tipo albun
                result = album.Albums.Select(item =>
                    {
                        // obtener la ultima imagen del album (En caso de no existir ninguna, no se añade el albun)
                        Microsoft.Xna.Framework.Media.Picture img = item.Pictures.LastOrDefault();
                        if (null == img) return null;

                        // crear y retornar el albun
                        return new AlbumItemModel()
                        {
                            Name = item.Name,
                            ItemType = enumAlbumItemTypes.ALBUM,
#if COSOS2DX
                            Image = img.GetThumbnail().
#else
                            Image = img.GetThumbnail().ConvertToBase64()
#endif
                        };
                    }).
                    OfType<AlbumItemModel>().    // ignorar valores nulos
                    Concat(                             // Concatenar con los items de tipo imagen                    
                    album.Pictures.Select(item => new AlbumItemModel()
                    {
                        Name = item.Name,
                        ItemType = enumAlbumItemTypes.IMAGE,
#if COSOS2DX
                        Image = item.GetThumbnail()
#else
                        Image = item.GetThumbnail().ConvertToBase64()
#endif
                    })).ToArray();
            }

            return (result.Length == 0) ? null : result;
        }

        /// <summary>
        /// Funcion para abrir el dialogo de seleccion de imagen y seleccionar una imagen
        /// </summary>
        /// <returns>Array de bytes con la imagen seleccionada, null en caso de no haberse seleccionado ninguna</returns>
        //public static async Task<byte[]> ChooseImage()
        //{

        //    //_refreshImageList();

        //    // resultado con la imagen
        //    byte[] photoBytes = null;

        //    // abrir el chooser y esperar el resultado
        //    var photoResult = await new PhotoChooserTask().ShowChooserAsync();

        //    // procesar el resultado
        //    if (photoResult.TaskResult == TaskResult.OK)
        //    {                
        //        using (photoResult.ChosenPhoto)
        //        {                    
        //            // convertir la foto en un array de bytes
        //            photoBytes = new byte[photoResult.ChosenPhoto.Length];
        //            photoResult.ChosenPhoto.Read(photoBytes, 0, photoBytes.Length);
        //        }
        //    }

        //    // retornar los bytes
        //    return photoBytes;
        //}

        ///// <summary>
        ///// Metodo de prueba Obtener carpetas WP8.1 ?
        ///// </summary>
        //public static async void test()
        //{
        //    // TODO: Obtener carpetas WP8.1 ?
        //        IReadOnlyList<Windows.Storage.StorageFolder> storageFolderList = await Windows.Storage.KnownFolders.PicturesLibrary.GetFoldersAsync();
        //    if (storageFolderList.Where(x => x.Name == "FolderName").Count() == 0)
        //    {
        //        Windows.Storage.StorageFolder folderCreationResult = await Windows.Storage.KnownFolders.PicturesLibrary.CreateFolderAsync("FolderName", Windows.Storage.CreationCollisionOption.ReplaceExisting);

        //        var messageDialog = "FolderName has been created";
        //    }
        //    else
        //    {
        //        var messageDialog = "FolderName already exists.";
        //    }
        //}

        #endregion [Funciones publicas]


        #region [Funciones privadas]

        /// <summary>
        /// Funcion para buscar el albun de imagenes de la biblioteca multimedia especificado por la ruta de entrada
        /// </summary>
        /// <param name="_path">Ruta del albun relativa al albun raiz '/'</param>
        /// <returns>Albun de imagenes de la biblioteca multimedia, null en caso de no encontrarse</returns>
        private static Microsoft.Xna.Framework.Media.PictureAlbum _findPictureAlbum(string _path)
        {
            Microsoft.Xna.Framework.Media.PictureAlbum result = null;

            // contexto para usar la libreria de acceso a imagenes
            using (var library = new Microsoft.Xna.Framework.Media.MediaLibrary())
            {
                // si la ruta es la raiz, se retorna el albun raiz
                if ("/" == _path) return library.RootPictureAlbum;

                // separar la ruta para buscar el albun
                string[] paths = _path.Split(new string[] { "/" }, StringSplitOptions.RemoveEmptyEntries);

                // recorrer paths para buscar el albun
                result = library.RootPictureAlbum;
                for (int i = 0; i < paths.Length; i++)
                {
                    // buscar el albun con el nombre correspondiente (si no se encuentra se retorna null)
                    Microsoft.Xna.Framework.Media.PictureAlbum currentAlbum = result.Albums.FirstOrDefault(item => item.Name == paths[i]);
                    if (null == currentAlbum) return null;

                    // albun actual
                    result = currentAlbum;
                }
            }

            // retornar el albun encontrado
            return result;
        }

        //private static void _refreshImageList()
        //{
        //    // limpiar lista de imagenes
        //    s_photoList.Clear();

        //    // obtener todas las imagenes
        //    using (var library = new Microsoft.Xna.Framework.Media.MediaLibrary())
        //    {
        //        _addAlbum(library.RootPictureAlbum, "/");
        //    }
        //}

        //private static void _addAlbum(Microsoft.Xna.Framework.Media.PictureAlbum _album, string _parentPath)
        //{           
        //    // añadir albums recursivamente
        //    foreach (Microsoft.Xna.Framework.Media.PictureAlbum childAlbum in _album.Albums)
        //    {
        //        _addAlbum(childAlbum, _parentPath + childAlbum.Name + "/");
        //    }

        //    // añadir todas las imagenes del album
        //    s_photoList.AddRange(_album.Pictures.Select(item => _parentPath + item.Name));
        //}



        
        #endregion [Funciones privadas]

    }
}
