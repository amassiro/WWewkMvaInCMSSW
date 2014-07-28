WWewkMvaInCMSSW
===============

WW2jewk Mva in cmssw

- to be loaded in cmssw

        In the same way of DYmva code

- to be used within the gardener


        gardener.py  wwewkMVAVar  -r /home/amassiro/Latinos/Shape/tree_skim_wwmin_2j_TEMP/wjetsTemplate  /home/amassiro/Latinos/Shape/tree_skim_wwmin_2j_wwewk/wjetsTemplate

        ls /home/amassiro/Latinos/Shape/tree_skim_wwmin_2j_TEMP/ --color=none | awk '{print "gardener.py  wwewkMVAVar -F -r /home/amassiro/Latinos/Shape/tree_skim_wwmin_2j_TEMP/"$1"  /home/amassiro/Latinos/Shape/tree_skim_wwmin_2j_wwewk/"$1}'




mva addition

    gardener.py  wwewkMVAVar  /data/amassiro/LatinosTrees/2jewk/nominals_all/latino_006_WWJets2LPowheg.root       /tmp/amassiro/latino_006_WWJets2LPowheg_new.root
    gardener.py  wwewkMVAVar  /data/amassiro/LatinosTrees/2jewk/nominals_all/latino_052_WW2JetsPhantom.root       /tmp/amassiro/latino_052_WW2JetsPhantom_new.root


    gardener.py  ww2jVar -F -r  /data/amassiro/LatinosTrees/2j/nominals_all/      /data/amassiro/LatinosTrees/2jewk_mva/nominals_all/
    gardener.py  ww2jVar -F -r  /data/amassiro/LatinosTrees/2j/wjets/             /data/amassiro/LatinosTrees/2jewk_mva/wjets/
    gardener.py  ww2jVar -F -r  /data/amassiro/LatinosTrees/2j/data/              /data/amassiro/LatinosTrees/2jewk_mva/data/




