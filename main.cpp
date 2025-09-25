#include <iostream>
#include <string>
int codigoProducto [100] = {101, 102, 103, 104, 105};
std::string nombreProducto [100] = {"Cinta de aislar", "Llave inglesa", "Taladro", "Esmeriladora", "Destornillador"}; //Variables globales
int stockProducto [100] = {75, 30, 7, 15, 60};
float precioUnitario [100] = {49.50, 704.00, 2565.00, 849.00, 289.00};
int menu = 1;
int menu2 = 0;
int consultarProducto = 1;
int nuevoCodigoProducto;

int main (){
    std::cout<<"--- Bienvenido al Sistema de Inventario \"El Martillo\" --- \n"<<std::endl;
    
    while (menu != 5)
    {
        std::cout<<"Seleccione una opcion: " <<std::endl;
        std::cout<<"1. Consultar un producto" <<std::endl;
        std::cout<<"2. Actualizar inventario" <<std::endl;
        std::cout<<"3. Generar reporte completo" <<std::endl;
        std::cout<<"4. Encontrar el producto mas caro" <<std::endl;
        std::cout<<"5. Salir" <<std::endl;
        std::cin >> menu;
        std::cout<<"Opcion seleccionada: " << menu << "\n" <<std::endl;
        
        switch (menu)
        {
        case 1:
            std::cout<<"Ingrese el codigo del producto a consultar: ";
            std::cin >> consultarProducto;
            for (int i = 0; i < 100; i++)
            {
                if (consultarProducto == codigoProducto[i])
                {
                    std::cout<<"Informacion del producto:"<<std::endl;
                    std::cout<<"Codigo: " << codigoProducto[i]<< std::endl;
                    std::cout<<"Nombre: " << nombreProducto[i]<< std::endl;
                    std::cout<<"Cantidad en stock: " << stockProducto[i]<< std::endl;
                    std::cout<<"Precio unitario: $" << precioUnitario[i]<<"\n"<< std::endl;
                    std::cout<<"--- Menu Principal --- \n"<<std::endl;
                    break; 
                } 
            }
            break;
            
        case 2:
            menu2 = 0; 
            while (menu2 != 3)
            {   
                std::cout<<"Que desea hacer?"<< "\n"<<std::endl;
                std::cout<<"1. Agregar producto" <<std::endl;
                std::cout<<"2. Actualizar informacion del producto" <<std::endl;
                std::cout<<"3. Salir al menu principal" <<std::endl;
                std::cin>>menu2; 
                std::cout<<"Opcion seleccionada: " << menu2 << "\n" <<std::endl;
                
                switch (menu2) 
                {
                case 1:
                    for (int i = 5; i < 100; i++)
                    {   
                        std::cout<<"Ingrese el nombre del nuevo producto:"<<std::endl;
                        std::cin>> nombreProducto[i];
                        std::cout<<"Ingrese el codigo del nuevo producto:"<<std::endl;
                        std::cin>> codigoProducto[i];
                        std::cout<<"Ingrese la cantidad en stock del nuevo producto:"<<std::endl;
                        std::cin>>stockProducto[i];
                        std::cout<<"Ingrese el precio unitario del nuevo producto:"<<std::endl;
                        std::cin>>precioUnitario[i];
                        std::cout <<"\n";
                        break;
                    }
                    break;

                case 2:
                    std::cout<<"Ingrese el codigo del producto: ";
                    std::cin >>consultarProducto;
                    for (int i = 0; i < 100; i++)
                    {
                        if (consultarProducto == codigoProducto[i])
                        {
                            std::cout<<"Producto encontrado: "<<nombreProducto[i] << std::endl;
                            std::cout<<"Ingrese el nuevo codigo del producto: " << std::endl;
                            std::cin >> codigoProducto[i];                
                            std::cout<<"Ingrese la nueva cantidad en stock: " << std::endl;
                            std::cin >> stockProducto[i];
                            std::cout<<"Ingrese el nuevo precio unitario:" << std::endl;
                            std::cin>>precioUnitario[i]; 
                            std::cout <<"\n";
                            break; 
                        }
                    }
                    break;

                case 3:
                    std::cout<<"--- Menu Principal --- \n"<<std::endl;
                    break;
                
                default:
                    std::cout<<"Opcion invalida. Intente nuevamente.\n"<<std::endl;
                    break;
                }
            }
            break;

        case 3:
            std::cout<<"--- Reporte de Inventario ---"<< std::endl;
            std::cout<<"Codigo       | Nombre               | Stock | Precio"<< std::endl;
            std::cout<<"----------------------------------------------------"<<std::endl;
            
            for (int i = 0; i < 100 && codigoProducto[i] > 0; i++)
            {
                std::cout<< codigoProducto[i] << "       | "<<nombreProducto[i]<<"   |"<<stockProducto[i]<<"   |$"<<precioUnitario[i]<<std::endl;
            }
            std::cout<<"----------------------------------------------------"<<std::endl;
            break;
        
        case 4:
            {
                float precioMaximo = 0.0;
                int indiceMasCaro = -1;
                
            
                for (int i = 0; i < 100; i++)
                {
                    
                    if (codigoProducto[i] > 0 && precioUnitario[i] > precioMaximo)
                    {
                        precioMaximo = precioUnitario[i];
                        indiceMasCaro = i;
                    }
                }
                
                if (indiceMasCaro != -1)
                {
                    std::cout << "El producto mas caro es: " << nombreProducto[indiceMasCaro] 
                              << " con un precio de $" << precioUnitario[indiceMasCaro] << "\n" << std::endl;
                }
                else
                {
                    std::cout << "No se encontraron productos en el inventario." << std::endl;
                }
            }
            break;

        case 5:
            std::cout<<"Ha salido del Sistema de Inventario \"El Martillo\" ---"<<std::endl;
            break;
            
        default:
            std::cout<<"Error, esa no es una opcion valida. Intente nuevamente. \n"<<std::endl;
            break;
        }
    }
    
    return 0; 
}
