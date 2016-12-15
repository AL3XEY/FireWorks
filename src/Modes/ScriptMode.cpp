#include "ScriptMode.h"

ScriptMode::ScriptMode(std::string filename) :
	DemoMode()
{

		//do
		//	read in
		//	if(...)
		//		do ...
		//	if(delay)
		//		take current time
		//		while(time not spent)
		//			take current time
		//			calculate delta
		//	if(...)
		//		do ...
		//while(not EOF)

		std::string delimiter = " ";
		std::string comment = "#";
		std::string token;
		std::ifstream myReadFile;
		char *cstr = new char[filename.length() + 1];
		strcpy_s(cstr, filename.length() + 1, filename.c_str());
		myReadFile.open(cstr);
		std::string buffer;
		size_t pos;
		int line = 1;
		double launchDelay, x, y, z, vx, vy, vz, r, g, b, a;
		//Firework firework;
		std::string currentFirework;
		if (myReadFile.is_open()) {
			do {
				getline(myReadFile, buffer);

				//TODO if substring[index] exists
				token = buffer.substr(0, buffer.find(delimiter));

				if (token == "firework"
					|| token == "sphere") {
					currentFirework = token;
					buffer.erase(0, buffer.find(delimiter) + delimiter.length());
					launchDelay = x = y = z = vx = vy = vz = r = g = b = a = 0;
					//do{
					if ((pos = buffer.find(delimiter)) != std::string::npos) {
						token = buffer.substr(0, buffer.find(delimiter));
						launchDelay = atof(token.c_str());
						buffer.erase(0, buffer.find(delimiter) + delimiter.length());

						if ((pos = buffer.find(delimiter)) != std::string::npos) {
							token = buffer.substr(0, buffer.find(delimiter));
							x = atof(token.c_str());
							buffer.erase(0, buffer.find(delimiter) + delimiter.length());
							if ((pos = buffer.find(delimiter)) != std::string::npos) {
								token = buffer.substr(0, buffer.find(delimiter));
								y = atof(token.c_str());
								buffer.erase(0, buffer.find(delimiter) + delimiter.length());
								if ((pos = buffer.find(delimiter)) != std::string::npos) {
									token = buffer.substr(0, buffer.find(delimiter));
									z = atof(token.c_str());
									buffer.erase(0, buffer.find(delimiter) + delimiter.length());
									if ((pos = buffer.find(delimiter)) != std::string::npos) {
										token = buffer.substr(0, buffer.find(delimiter));
										vx = atof(token.c_str());
										buffer.erase(0, buffer.find(delimiter) + delimiter.length());
										if ((pos = buffer.find(delimiter)) != std::string::npos) {
											token = buffer.substr(0, buffer.find(delimiter));
											vy = atof(token.c_str());
											buffer.erase(0, buffer.find(delimiter) + delimiter.length());
											if ((pos = buffer.find(delimiter)) != std::string::npos) {
												token = buffer.substr(0, buffer.find(delimiter));
												vz = atof(token.c_str());
												buffer.erase(0, buffer.find(delimiter) + delimiter.length());
												if ((pos = buffer.find(delimiter)) != std::string::npos) {
													token = buffer.substr(0, buffer.find(delimiter));
													r = atof(token.c_str());
													buffer.erase(0, buffer.find(delimiter) + delimiter.length());
													if ((pos = buffer.find(delimiter)) != std::string::npos) {
														token = buffer.substr(0, buffer.find(delimiter));
														g = atof(token.c_str());
														buffer.erase(0, buffer.find(delimiter) + delimiter.length());
														if ((pos = buffer.find(delimiter)) != std::string::npos) {
															token = buffer.substr(0, buffer.find(delimiter));
															b = atof(token.c_str());
															buffer.erase(0, buffer.find(delimiter) + delimiter.length());
															if ((pos = buffer.find(delimiter)) != std::string::npos) {
																token = buffer.substr(0, buffer.find(delimiter));
																a = atof(token.c_str());
																buffer.erase(0, buffer.find(delimiter) + delimiter.length());

															}
														}
													}
												}
											}
										}
									}
								}
							}
						}



						
					}
					//buffer.erase(0, buffer.find(delimiter) + delimiter.length());
					//}while((pos = buffer.find(delimiter)) != std::string::npos);

					//ExplosiveFirework firework();

					vect_fw.push_back(std::move(std::unique_ptr<AbstractFirework>(new ExplosiveFirework())));

					std::cout << "delay = " << launchDelay << std::endl;
					std::cout << "x = " << x << std::endl;
					std::cout << "y = " << y << std::endl;
				}
				std::cout << line << ":: " << token << std::endl;
				line++;
			} while (!myReadFile.eof());
		}
		myReadFile.close();
		delete[] cstr;


		/*if (!arg.compare(0, comment.size(), comment){
		buffer.erase(0, buffer.find(delimiter) + delimiter.length());
		}*/

		/*
		
		// Ajout de Fireworks
		double r = (double(rand()) / double(RAND_MAX));
		//
		if (r < 0.01)
		vect_fw.push_back(std::move(std::unique_ptr<AbstractFirework>(new HeartFirework)));
		else if (r < 0.02)
		vect_fw.push_back(std::move(std::unique_ptr<AbstractFirework>(new SphereFirework)));
		else if (r < 0.03)
		vect_fw.push_back(std::move(std::unique_ptr<AbstractFirework>(new Firework)));
		else if (r < 0.04)
		vect_fw.push_back(std::move(std::unique_ptr<AbstractFirework>(new BoxFirework)));
		else if (r < 0.05)
		vect_fw.push_back(std::move(std::unique_ptr<AbstractFirework>(new ExplosiveFirework())));
		//

		if (r < 0.1)
			vect_fw.push_back(std::move(std::unique_ptr<AbstractFirework>(new ExplosiveFirework())));
		//vect_fw.push_back(std::move(std::unique_ptr<AbstractFirework>(new Firework)));

		for (unsigned int i = 0; i < vect_fw.size(); i++) {
			if (vect_fw.at(i)->done()) {
				vect_fw.erase(vect_fw.begin() + i);
				i--;
			}
		}

		*/

}

ScriptMode::~ScriptMode()
{
}

void ScriptMode::update()
{
	manageEvents();

	manageCamera();

	for (auto fw(vect_fw.begin()), ite(vect_fw.end()); fw != ite; fw++) {
		(*fw)->tick();
		(*fw)->updateData();
		(*fw)->move();
		(*fw)->applyForce(0.0, AbstractFirework::GRAVITY, 0.0);
	}
}
