pipeline {
  agent{
    dockerfile {
      filename 'Dockerfile'
      dir 'build_env'
    }
  }

  stages {
    stage('SCM') {
      steps{
        checkout(
          [
            $class: 'GitSCM',
            branches: [[name:'main']], 
            userRemoteConfigs: [[url: 'https://github.com/rkenyon3/adventurer.git']]
          ]
        )
      }
    }

    stage('Build') {
      steps {
        cd adventurer
        mkdir build
        cd build
        sh "cmake ../src"
        sh "cmake --build ."
      }
    }    
  }
}
