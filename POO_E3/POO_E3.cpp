#include <iostream>
#include <string>

namespace PooBriguera
{

    class VersionInfo
    {
     private:
        std::string version;
        std::string lastUpdateDate;

     public:
        VersionInfo(const std::string& version, const std::string& lastUpdateDate)
            : version(version), lastUpdateDate(lastUpdateDate) {}

        // Función para obtener el número de versión
        std::string getVersion() const {
            return version;
        }

        // Función para obtener la fecha de última actualización
        std::string getLastUpdateDate() const {
            return lastUpdateDate;
        }


    };

    VersionInfo obtenerVersion()
    {
        return VersionInfo("1.0", "23-03-2024");
    }
}

int main()
{
    // Obtener la información de versión y fecha de actualización
    PooBriguera::VersionInfo info = PooBriguera::obtenerVersion();

    // Imprimir la información obtenida
    std::cout << "Numero de version: " << info.getVersion() << std::endl;
    std::cout << "Fecha de ultima actualizacion: " << info.getLastUpdateDate() << std::endl;

    return 0;
}
