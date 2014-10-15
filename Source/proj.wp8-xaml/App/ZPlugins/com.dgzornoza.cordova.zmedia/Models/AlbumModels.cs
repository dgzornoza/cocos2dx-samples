using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace com.dgzornoza.cordova.plugins.Models
{
    /// <summary>
    /// Enumeracion con los diferentes tipos de albunes que pueden usarse
    /// </summary>
    public enum enumAlbumTypes
    {
        /// <summary>Albun de imagenes</summary>
        PICTURES = 0,
    }

    /// <summary>
    /// Enumeracion con los diferentes tipos de items existentes en los albunes
    /// </summary>
    public enum enumAlbumItemTypes
    {
        /// <summary>Item de tipo albun, que a su vez puede contener mas items</summary>
        ALBUM = 0,
        /// <summary>Item de tipo imagen</summary>
        IMAGE = 1
    }

    /// <summary>
    /// Clase con un modelo para representar un album de imagenes
    /// </summary>
    public class AlbumItemModel
    {
        /// <summary>Nombre del item</summary>
        public string Name { get; set; }

        /// <summary>Tipo de item en el albun</summary>
        public enumAlbumItemTypes ItemType { get; set; }

#if COSOS2DX
        /// <summary>Image del item</summary>
        public byte[] Image { get; set; }
#else
        /// <summary>Image del item en base 64</summary>
        public string Image { get; set; }
#endif

    }

    /// <summary>
    /// Clase con un modelo conteniendo un filtro para usar en operaciones con albunes
    /// </summary>
    public class AlbumFilterModel
    {
        /// <summary>Ruta del albun relativa al albun raiz ("/" para el albun raiz, los hijos se anidan ej: "/Pictures/Folder/</summary>
        public string Path { get; set; }

        /// <summary>Tipo de albun a usar, especificado por la enumeracion <see cref="enumAlbumTypes"/>.</summary>
        public enumAlbumTypes AlbumType { get; set; }
    }
    
}
