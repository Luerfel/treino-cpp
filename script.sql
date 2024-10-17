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
