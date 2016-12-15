#include "ScriptMode.h"

ScriptMode::ScriptMode(std::string filename) :
	DemoMode()
{

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
		std::string currentFirework;
		if (myReadFile.is_open()) {
			do {
				getline(myReadFile, buffer);

				//TODO if substring[index] exists
				token = buffer.substr(0, buffer.find(delimiter));

				if (token == "explosive"
					|| token == "sphere"
					|| token == "heart") {
					currentFirework = token;
					buffer.erase(0, buffer.find(delimiter) + delimiter.length());
					launchDelay = vx = vz = a = 0;
					x = z =-100.0;
					y = 1.0;
					vy = 2.0;
					r = g = b = 255.0;
					//AbstractFirework::

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

					if(currentFirework == "explosive")
						vect_fw.push_back(std::move(std::unique_ptr<AbstractFirework>(new ExplosiveFirework(launchDelay, x, y, z, vx, vy, vz, r, g, b, a))));
					if (currentFirework == "sphere")
						vect_fw.push_back(std::move(std::unique_ptr<AbstractFirework>(new SphereFirework(launchDelay, x, y, z, vx, vy, vz, r, g, b, a))));
					if (currentFirework == "heart")
						vect_fw.push_back(std::move(std::unique_ptr<AbstractFirework>(new HeartFirework(launchDelay, x, y, z, vx, vy, vz, r, g, b, a))));

					//std::cout << "delay = " << launchDelay << std::endl;
	
				}
				std::cout << line << ":: " << token << std::endl;
				line++;
			} while (!myReadFile.eof());
		}
		myReadFile.close();
		delete[] cstr;

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
