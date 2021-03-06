# --------------------------------------------------------
# Host:                         127.0.0.1
# Server version:               5.3.1-MariaDB
# Server OS:                    Win32
# HeidiSQL version:             6.0.0.3603
# Date/time:                    2011-10-16 19:39:53
# --------------------------------------------------------

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET NAMES utf8 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;

use galaxy;

# Dumping structure for function galaxy.sf_SpeciesShort
DELIMITER //
CREATE DEFINER=`root`@`localhost` FUNCTION `sf_SpeciesShort`(species CHAR(128)) RETURNS char(128) CHARSET utf8
BEGIN
   	DECLARE SpeciesShort CHAR(128);

    	SET species = REPLACE(species,'object/creature/player/shared_','object/creature/player/');

		SELECT SUBSTRING_INDEX(TRIM(LEADING 'object/creature/player/' FROM species),'_',1) INTO SpeciesShort;
		RETURN speciesShort;
END//
DELIMITER ;
/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
