CREATE TABLE pessoa(
nome varchar(100) NOT NULL,
email varchar(100) NOT NULL,
CPF varchar(20) NOT NULL,
RG varchar(20) NOT NULL,
orgaomissorRG varchar(50) NOT NULL,
senha varchar(10) DEFAULT '123456',
idEndereco int NOT NULL,
qtdeFilhos int NOT NULL DEFAULT 0
CONSTRAINT pk_pessoa PRIMARY KEY(CPF),
CONSTRAINT fk2_pessoa FOREIGN KEY(idEndereco) REFERENCES endereco(idEndereco),
CHECK (email LIKE '%_@_%_.__%'),
CHECK (CPF LIKE '___.___.___-__'),
CHECK (qtdeFilhos >= 0)
);


CREATE TABLE telefone(
numero varchar(9) NOT NULL,
tipo char(1) DEFAULT 'R',
CPF varchar(20) NOT NULL,
CONSTRAINT pk_telefone PRIMARY KEY(numero),
CONSTRAINT fk_telefone FOREIGN KEY(CPF) REFERENCES pessoa(CPF),
CHECK (tipo IN ('R', 'E') )
);

CREATE TABLE empresa(
nome varchar(50) NOT NULL,
razaosocial varchar(100) NOT NULL,
idEndereco int NOT NULL,
CNPJ varchar(20) NOT NULL,
email varchar(50) NOT NULL,
idResponsavel varchar(20) NOT NULL,
CONSTRAINT pk_empresa PRIMARY KEY(CNPJ),
CONSTRAINT fk_empresa FOREIGN KEY(idEndereco) REFERENCES endereco(idEndereco),
CONSTRAINT fk2_empresa FOREIGN KEY(idResponsavel) REFERENCES pessoa(CPF),
CHECK (email LIKE '%_@_%_.__%'),
CHECK (CNPJ LIKE '__.___.___/____-__')
);

create table tbr_pessoa_empresa(
id_tbr_pessoa_empresa int identity(1,1),
CPF varchar(20) NOT NULL,
CNPJ varchar(20) NOT NULL,
CONSTRAINT pk_tbr_pessoa_empresa PRIMARY KEY(id_tbr_pessoa_empresa),
CONSTRAINT fk1_tbr_pessoa_empresa FOREIGN KEY(CPF) REFERENCES pessoa(CPF),
CONSTRAINT fk2_tbr_pessoa_empresa FOREIGN KEY(CNPJ) REFERENCES empresa(CNPJ)
);
