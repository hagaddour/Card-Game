CXX = g++
CXXFLAGS = -g -std=c++14 -Wall -MMD -Werror=vla -lX11
EXEC = sorcery
OBJECTS = main.o board.o deck.o card.o print.o ascii_graphics.o window.o graphicsdisplay.o enchantment.o minion.o player.o ritual.o spell.o ability.o airElemental.o apprenticeSummoner.o auraOfPower.o banish.o blizzard.o darkRitual.o disenchant.o earthElemental.o fireElemental.o giantStrength.o magicFatigue.o masterSummoner.o novicePyromancer.o potionSeller.o raiseDead.o recharge.o silence.o standstill.o unsummon.o enrage.o haste.o boneGolem.o

DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${OBJECTS} -o ${EXEC} ${CXXFLAGS}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}

