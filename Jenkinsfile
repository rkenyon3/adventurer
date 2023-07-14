pipeline {
  agent{
  	dockerfile {
  		filename 'Dockerfile'
  		dir 'build_env'
  	}
  }
  stages {
    stage('Build') {
      steps {
        mkdir build
        checkout(
        	[
        		$class: 'GitSCM',
        		branches: [[name:'*/main']], 
        		userRemoteConfigs: [[url: 'https://github.com/rkenyon3/adventurer.git']]
        	]
      	)
      }
    }

  }
}
