package jiraiya.game.controll;

import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.nodes.Scene;

public class SceneMaker {
	public static Scene makeSceneWithLayer(Layer _layer){
		Scene _scene = Scene.make();
        _scene.addChild(_layer);
        return _scene;
	} 
}
