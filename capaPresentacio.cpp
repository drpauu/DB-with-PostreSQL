#include "capaPresentacio.h"

capaPresentacio& capaPresentacio::getInstance() {
	static capaPresentacio instance;
	return instance;
}

capaPresentacio::~capaPresentacio() {

}

//Funcio privada per comprovar que el correu te un format correcte
bool capaPresentacio::comprovarCorreu(string s) {
	regex pattern(R"(^[_a-z0-9-]*@[a-z0-9-]+(\.[a-z]{2,4})+$)");
	return regex_match(s, pattern);
}

//Funcio privada per comprovar que la data introduida per l'usuari te un format correcte
bool capaPresentacio::comprovarData(string data) {
	istringstream data_str(data);
	bool validesa = false;
	int dia, mes, any;
	char delimiter;
	//Extreu els valors en el cas de format DD/MM/AAAA
	data_str >> dia >> delimiter >> mes >> delimiter >> any;

	struct tm input;
	input.tm_year = any - 1900; input.tm_mon = mes - 1; input.tm_mday = dia;
	input.tm_hour = 0; input.tm_min = 0; input.tm_sec = 0;

	time_t ara = time(0);
	struct tm temps;
	localtime_s(&temps, &ara);

	double diff = difftime(mktime(&temps), mktime(&input));

	if (data_str.eof() && delimiter == '/' && dia >= 1 && dia <= 31 && mes >= 1 && mes <= 12 && any > 0 && diff > 0) validesa = true;
	return validesa;
}

//Funcio per traduir el format entre el que s'utilitza a la interfície i la que s'utilitza a la base de dades
string capaPresentacio::dataFormatter(string data) {
	size_t counter;
	char delimiter;
	string new_str;
	istringstream data_str(data);
	counter = data.find('/');
	int dia, mes, any;
	if (counter == 2 || counter == 1) {
		data_str >> dia >> delimiter >> mes >> delimiter >> any;
		new_str = to_string(any) + "-" + to_string(mes) + "-" + to_string(dia);
	}
	else if (counter == -1) {
		data_str >> any >> delimiter >> mes >> delimiter >> dia;
		new_str = to_string(dia) + "/" + to_string(mes) + "/" + to_string(any);
	}
	return new_str;
}

bool capaPresentacio::iniciarSessioPres() {
	cin.ignore();
	system("CLS");
	string s, c;
	cout << "** Inici sessio **" << "\n";
	cout << "Sobrenom: ";
	getline(cin, s);
	cout << "Contrasenya: ";
	getline(cin, c);
	TXiniciarSessio is(s, c);
	try{
		is.executar();
	}
	catch(...){
		cout << "Usuari o contrasenya incorrecta" << "\n" << "\n";
	}
	if (is.obteResultat()) cout << "Sessio iniciada correctament!" << "\n" << "\n";
	return is.obteResultat();
}

bool capaPresentacio::tancarSessioPres() {
	cin.ignore();
	system("CLS");
	string op;
	cout << "** Tancar sessio **" << "\n";
	cout << "Vols tancar la sessio (S/N): ";
	cin >> op;
	TXtancarSessio ts;
	if (op == "S") {
		ts.executar();
		cout << "Sessio tancada correctament!" << "\n" << "\n";
	}
	else if (op == "N") {
		cout << "\n";
		return true;
	}
	else {
		cout << "Has de contestar amb S o N!" << "\n" << "\n";
	}
	return ts.obteResultat();
}

void capaPresentacio::registrarUsuariPres() {
	cin.ignore();
	system("CLS");
	string nom, sobrenom, contrasenya, correuE, dataN;
	cout << "----- CREACIO D'UN NOU USUARI -----" << "\n";
	cout << "Nom (complet): ";
	getline(cin, nom);
	cout << "Sobrenom: ";
	getline(cin, sobrenom);
	cout << "Contrasenya: ";
	getline(cin, contrasenya);
	cout << "Correu electronic: ";
	getline(cin, correuE);
	if (!comprovarCorreu(correuE)) {
		cout << "Error: Correu no valid." << "\n" << "\n";
		return;
	}
	cout << "Data de naixement (DD/MM/AAAA): ";
	getline(cin, dataN);
	if (!comprovarData(dataN)) {
		cout << "Error: Data no valida" << "\n" << "\n";
		return;
	}
	TXregistrarUsuari ru(nom, sobrenom, contrasenya, correuE, dataFormatter(dataN));
	try {
		ru.executar();
	}
	catch (exception &e) {
		cout << "Error: " << e.what() << "\n" << "\n";
		return;
	}
	cout << "Usuari registrat correctament!" << "\n" << "\n";
}

void capaPresentacio::consultarUsuariPres() {
	cin.ignore();
	system("CLS");
	cout << "** Consulta usuari **" << "\n";
	TXconsultarUsuari cu;
	try {
		cu.executar();
	}
	catch (const exception& e) {
		cout << "Error: " << e.what() << "\n" << "\n";
	}
	TXconsultarUsuari::res r1 = cu.obteResultat();
	cout << "Nom complet: " << r1.nom << "\n";
	cout << "Sobrenom: " << r1.sobrenom << "\n";
	cout << "Correu electronic: " << r1.correu << "\n";
	cout << "Data naixement (DD/MM/AAAA): " << dataFormatter(r1.dataN) << "\n";
	cout << "\n";
	TXconsultarCompres cc;
	try {
		cc.executar();
		TXconsultarCompres::res r2 = cc.obteResultat();
		cout << r2.videojocs << " videojocs comprats." << "\n";
		cout << r2.paquets << " paquets de videojocs comprats." << "\n";
		cout << r2.total << " euros gastats en total." << "\n" << "\n";
	}
	catch (const exception& e) {
		cout << "Error: " << e.what() << "\n" << "\n";
	}
}

void capaPresentacio::modificarUsuariPres() {
	cin.ignore();
	system("CLS");
	string input;
	cout << "** Modifica usuari **" << "\n" << "\n";
	CUmodificaUsuari mu;
	TXconsultarUsuari::res r = mu.consultaUsuari();
	cout << "Nom complet: " << r.nom << "\n";
	cout << "Sobrenom: " << r.sobrenom << "\n";
	cout << "Correu electronic " << r.correu << "\n";
	cout << "Data naixement (DD/MM/AAAA): " << dataFormatter(r.dataN) << "\n" << "\n";
	cout << "*********************************************" << "\n";
	cout << "Omplir la informacio que es vol modificar ..." << "\n";
	cout << "Nom complet: ";
	getline(cin, input);
	if (input.size() != 0) r.nom = input;
	cout << "Contrasenya: ";
	getline(cin, input);
	if (input.size() != 0) r.contrasenya = input;
	cout << "Correu electronic: ";
	getline(cin, input);
	if (comprovarCorreu(input)) r.correu = input;
	cout << "Data naixement (DD/MM/AAAA): ";
	getline(cin, input);
	if (input.size() != 0) {
		if (!comprovarData(input)) {
			cout << "Error: Data no valida." << "\n" << "\n";
			return;
		}
		r.dataN = dataFormatter(input);
	}
	try {
		mu.modificaUsuari(r.nom, r.contrasenya, r.correu, r.dataN);
		cout << "**************Dades modificades**************" << "\n";
		r = mu.consultaUsuari();
		cout << "Nom complet: " << r.nom << "\n";
		cout << "Sobrenom: " << r.sobrenom << "\n";
		cout << "Correu electronic " << r.correu << "\n";
		cout << "Data naixement (DD/MM/AAAA): " << dataFormatter(r.dataN) << "\n" << "\n";
	}
	catch (const exception& e) {
		cout << "Error: " << e.what() << "\n" << "\n";
	}
}

bool capaPresentacio::esborrarUsuariPres() {
	cin.ignore();
	system("CLS");
	string c;
	cout << "** Esborrar usuari **" << "\n";
	cout << "Introdueix la teva contrasenya per confirmar l'esborrat: ";
	cin >> c;
	TXesborrarUsuari eu(c);
	try {
		eu.executar();
		cout << "Usuari esborrat correctament!" << "\n" << "\n";
	}
	catch (const exception& e) {
		cout << e.what() << "\n" << "\n";
	}
	return eu.obteResultat();
}

void capaPresentacio::comprarVideojocPres() {
	cin.ignore();
	system("CLS");
	string vid;
	cout << "** Comprar videojoc **" << "\n";
	cout << "Nom videojoc: ";
	getline(cin, vid);
	TXconsultarVideojoc cv(vid);
	try {
		cv.executar();
	}
	catch (const exception& e) {
		cout << e.what() << "\n" << "\n";
		return;
	}
	cout << "\n" << "Informacio sobre el videojoc..." << "\n" << "\n";
	TXconsultarVideojoc::res r = cv.obteResultat();
	cout << "Nom videojoc: " << r.nom << "\n";
	cout << "Descripcio: " << r.desc << "\n";
	cout << "Qualificacio edat: " << r.qualificacio << "\n";
	cout << "Genere: " << r.genere << "\n";
	cout << "Data llancament: " << dataFormatter(r.data) << "\n";
	cout << "Preu: " << r.preu << " euros" << "\n";
	cout << "\n";
	cout << "Vols continuar amb la compra (S/N): ";
	char conf;
	cin >> conf;
	cout << "\n";
	TXcomprarVideojoc comv(vid);
	if (conf == 'S') {
		try {
			comv.executar();
		}
		catch (const exception& e) {
			cout << "Error: " << e.what() << "\n" << "\n";
			return;
		}
	}
	else return;
	TXcomprarVideojoc::res rec = comv.obteResultat();
	cout << "Compra registrada: " << dataFormatter(rec.data) << "\n" << "\n";
	cout << "Jocs relacionats : " << "\n";
	for (int i = 0; i < rec.recomanats.size(); i++) {
		cout << "- " << rec.recomanats[i].nom << "; " << rec.recomanats[i].desc << "; " << rec.recomanats[i].preu << " euros" << "\n";
	}
	cout << "\n";
}

void capaPresentacio::comprarPaquetPres() {
	cin.ignore();
	system("CLS");
	string paq;
	cout << "** Comprar paquet **" << "\n";
	cout << "Nom paquet: ";
	getline(cin, paq);
	TXconsultarPaquet cp(paq);
	try {
		cp.executar();
	}
	catch (const exception& e) {
		cout << e.what() << "\n" << "\n";
		return;
	}
	cout << "Informacio sobre el paquet..." << "\n";
	TXconsultarPaquet::res r = cp.obteResultat();
	cout << "Nom paquet: " << r.nom << "\n";
	cout << "Descripcio: " << r.desc << "\n";
	cout << "Preu: " << r.preu << " euros (estalvi de " << r.estalvi << " euros)" << "\n";
	cout << "\n";
	cout << "Jocs inclosos: " << "\n" << "\n";
	for (int i = 0; i < r.vnoms.size(); i++) {
		cout << "> " << r.vnoms[i] << "; " << r.vdescs[i] << "; " << r.vpreus[i] << " euros" << "\n";
	}
	cout << "\n" << "Vols continuar amb la compra (S/N): ";
	char conf;
	cin >> conf;
	TXcomprarPaquet comp(paq);
	if (conf == 'S') {
		try {
			comp.executar();
			string res = comp.obteResultat();
			cout << "\n" << "Compra registrada: " << dataFormatter(res) << "\n";
		}
		catch (const exception& e) {
			cout << "Error: " << e.what() << "\n" << "\n";
			return;
		}
	}
	cout << "\n";
}

void capaPresentacio::consultarCompresPres() {
	cin.ignore();
	system("CLS");
	cout << "** Consulta compres **" << "\n" << "\n";
	TXconsultarCompres cc;
	try {
		cc.executar();
	}
	catch (const exception& e) {
		cout << "Error: " << e.what() << "\n" << "\n";
	}
	TXconsultarCompres::res r = cc.obteResultat();
	for (int i = 0; i < r.elements.size(); i++) {
		cout << dataFormatter(r.elements[i].data) << " " << r.elements[i].tipus << " " << r.elements[i].nom << "; " << r.elements[i].desc << "; " << r.elements[i].preu << " euros" << "\n";
		if (r.elements[i].tipus == "paquet") {
			cout << "    Videojocs inclosos a la compra del paquet:" << "\n";
			for (int j = 0; j < r.elements[i].nomv.size(); j++) cout << "        " << r.elements[i].nomv[j] << "; " << r.elements[i].descv[j] << "\n";
		}
		cout << "\n";
	}
	cout << "Total: " << r.total << " euros." << "\n";
	cout << "\n";
}

void capaPresentacio::consultarVideojocPres() {
	cin.ignore();
	system("CLS");
	string s;
	cout << "** Consulta videojoc **" << "\n";
	cout << "Introdueix el nom del videojoc a consultar : ";
	getline(cin, s);
	TXconsultarVideojoc cv(s);
	try {
		cv.executar();
	}
	catch (const exception& e) {
		cout << e.what() << "\n" << "\n";
		return;
	}
	cout << "\n" << "Informacio sobre el videojoc..." << "\n" << "\n";
	TXconsultarVideojoc::res r = cv.obteResultat();
	cout << "Nom videojoc: " << r.nom << "\n";
	cout << "Descripcio: " << r.desc << "\n";
	cout << "Qualificacio edat: " << r.qualificacio << "\n";
	cout << "Genere: " << r.genere << "\n";
	cout << "Data llancament: " << dataFormatter(r.data) << "\n";
	cout << "Preu: " << r.preu << " euros" << "\n";
	cout << "Paquets on esta inclos: ";
	for (int i = 0; i < r.paquets.size(); i++) {
		if (i == r.paquets.size() - 1) cout << r.paquets[i] << "\n";
		else cout << r.paquets[i] << ", ";
	}
	cout << "\n";
}

void capaPresentacio::consultarVideojocsPres() {
	cin.ignore();
	system("CLS");
	cout << "** Consulta tots els videojocs **" << "\n";
	TXconsultarVideojocs cv;
	cv.executar();
	cout << "\n" << "Informacio sobre els videojocs..." << "\n" << "\n";
	vector<TXconsultarVideojocs::res> r = cv.obteResultat();
	for (int i = 0; i < r.size(); i++) {
		cout << "Nom videojoc: " << r[i].nom << "\n";
		cout << "Descripcio: " << r[i].desc << "\n";
		cout << "Qualificacio edat: " << r[i].qualificacio << "\n";
		cout << "Genere: " << r[i].genere << "\n";
		cout << "Data llancament: " << dataFormatter(r[i].data) << "\n";
		cout << "Preu: " << r[i].preu << " euros" << "\n";
		cout << "Paquets on esta inclos: ";
		for (int j = 0; j < r[i].paquets.size(); j++) {
			if (j == r[i].paquets.size() - 1) cout << r[i].paquets[j];
			else cout << r[i].paquets[j] << ", ";
		}
		if (i != r.size() - 1) cout << "\n" << "-----------------------------" << "\n";
	}
	cout << "\n" << "\n";
}
void capaPresentacio::consultarVideojocsEdatPres() {
	cin.ignore();
	system("CLS");
	int edat;
	cout << "** Consulta videojocs per edat **" << "\n";
	cout << "Edat maxima (anys): ";
	cin >> edat;
	if (edat <= 0) {
		cout << "Introdueix una edat superior a 0." << "\n";
		return;
	}
	TXconsultarVideojocsPerEdat cv(edat);
	cv.executar();
	cout << "\n" << "** Consulta videojocs fins a " << edat << " anys **" << "\n" << "\n";
	vector<TXconsultarVideojocsPerEdat::res> r = cv.obteResultat();
	for (int i = 0; i < r.size(); i++) {
		cout << r[i].nom << "; " << r[i].desc << "; " << r[i].preu << "; " << r[i].qualificacio << " PEGI" << "; " << r[i].genere << "; " << dataFormatter(r[i].data);
		if (r[i].paquets.size() != 0) cout << "; Paquets: ";
		for (int j = 0; j < r[i].paquets.size(); j++) {
			if (j == r[i].paquets.size() - 1) cout << r[i].paquets[j];
			else cout << r[i].paquets[j] << ", ";
		}
		if (i != r.size() - 1) cout << "\n" << "\n";
	}
	cout << "\n" << "\n";
}

void capaPresentacio::consultarNovetatsPres() {
	cin.ignore();
	system("CLS");
	string data;
	cout << "** Consulta novetats **" << "\n";
	cout << "Data (DD/MM/AAAA): ";
	getline(cin, data);
	if (data.size() > 0 && !comprovarData(data)) {
		cout << "Error: Data no valida." << "\n" << "\n";
		return;
	}
	if (data.size() == 0) { //Si l'usuari no entra cap data, es fa la cerca amb la data actual
		time_t ara = time(0);
		struct tm temps;
		localtime_s(&temps, &ara);
		data = to_string(temps.tm_year + 1900) + "-" + to_string(temps.tm_mon + 1) + "-" + to_string(temps.tm_mday);
		data = dataFormatter(data);
	}
	TXconsultarNovetats cn(dataFormatter(data));
	cn.executar();
	vector<TXconsultarNovetats::res> r = cn.obteResultat();
	cout << "\n" << "Videojocs llancats a partir del " << data << ":" << "\n" << "\n";
	for (int i = 0; i < r.size(); i++) {
		cout << r[i].nom << "; " << r[i].desc << "; " << r[i].preu << " euros; " << r[i].qualificacio << " PEGI; " << r[i].genere << "; " << dataFormatter(r[i].data);
		if (r[i].paquets.size() != 0) cout << "; Paquets: ";
		for (int j = 0; j < r[i].paquets.size(); j++) {
			if (j == r[i].paquets.size() - 1) cout << r[i].paquets[j];
			else cout << r[i].paquets[j] << ", ";
		}
		cout << "\n" << "\n";
	}
}

void capaPresentacio::consultarPaquetPres() {
	cin.ignore();
	system("CLS");
	string nPaquet;
	cout << "** Consulta paquet **" << "\n";
	cout << "Nom paquet: ";
	getline(cin, nPaquet);
	TXconsultarPaquet cp(nPaquet);
	try {
		cp.executar();
	}
	catch (const exception& e) {
		cout << e.what() << "\n" << "\n";
		return;
	}
	TXconsultarPaquet::res r = cp.obteResultat();
	cout << "Informacio paquet ..." << "\n" << "\n";
	cout << "Nom paquet: " << r.nom << "\n" << "\n";
	cout << "Descripcio: " << r.desc << "\n" << "\n";
	cout << "Preu: " << r.preu << " euros (estalvi de " << r.estalvi << " euros)" << "\n" << "\n";
	cout << "\n";
	cout << "Jocs inclosos:" << "\n";
	for (int i = 0; i < r.vnoms.size(); i++) cout << "- " << r.vnoms[i] << "; " << r.vdescs[i] << "; " << r.vpreus[i] << " euros" << "\n" << "\n";
	cout << "\n";
}

void capaPresentacio::consultarPaquetsPres() {
	cin.ignore();
	system("CLS");
	cout << "** Consulta paquets **" << "\n";
	TXconsultarPaquets cp;
	cp.executar();
	vector<TXconsultarPaquets::res> paquets = cp.obteResultat();
	for (auto& paquet : paquets) cout << paquet.nom << "; " << paquet.desc << "; " << paquet.preu << " euros (ESTALVI: " << paquet.estalvi << " euros)" << "\n" << "\n";
}
