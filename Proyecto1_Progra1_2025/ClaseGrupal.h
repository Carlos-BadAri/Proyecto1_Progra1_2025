Cliente** vClientes;
int cant;
int capacidadMax;//Este es tam
int salon;
string horario;
Instructor* ins;

public:
	ClaseGrupal(string, char, int, int, string, Instructor*);
	ClaseGrupal();

	void setCodigo(string);
	void setTipo(char);
	void setCapacidad(int);
	void setSalon(int);
	void setHorario(string);

	string getCodigo();
	char getTipo();
	int getCapacidad();
	int getSalon();
	string getHorario();

	bool agregarCliente(Cliente* c);

	bool eliminarCliente(string idCliente);
	string listarClientes();

	int getCant();

	string toString();
	~ClaseGrupal();

};